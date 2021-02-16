#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/image_io.h>
#include <iostream>
#include "dlibfacemarker.h"
using namespace dlib;
using namespace std;

typedef struct _XY {
    unsigned short x;
    unsigned short y;
} XY;

class FaceMarker {
private:
    frontal_face_detector detector = get_frontal_face_detector();
    shape_predictor sp;
public:
    FaceMarker(const char * model_path);
    unsigned long run(const char * photo_path, const void * buffer, const unsigned long size);
};

FaceMarker::FaceMarker(const char * model_path) {
    deserialize(model_path) >> sp;
}

unsigned long FaceMarker::run(const char * photo_path, const void * buffer, const unsigned long size) {
    array2d<rgb_pixel> img;
    #if DEBUG
    FILE * log = fopen("/tmp/fm.log", "w");
    fprintf(log, "preparing %lu for file %s\n", size, photo_path);
    #endif
    load_image(img, photo_path);
    #if DEBUG
    fprintf(log, "file %s loaded\n", photo_path);
    #endif
    std::vector<rectangle> dets = this->detector(img);
    #if DEBUG
    fprintf(log, "%lu detected\n", dets.size());
    #endif
    unsigned long total = 0;
    XY * marks = (XY *)buffer;
    #if DEBUG
    fprintf(log, "%lu buffered\n", size);
    #endif
    int completed = 0;
    for (unsigned long j = 0; j < dets.size(); ++j)
    {
        full_object_detection shape = sp(img, dets[j]);
        #if DEBUG
        fprintf(log, "checking shape #%lu, %lu parts\n", j, shape.num_parts());
        #endif
        unsigned long parts = shape.num_parts();
        if (parts != size) continue;
        for(unsigned long i = 0; i < shape.num_parts(); i++) {
            point p = shape.part(i);
            unsigned short x = (unsigned short)p.x();
            unsigned short y = (unsigned short)p.y();
            #if DEBUG
            fprintf(log, "feeding point %lu :: %lu (%u %u)\n", i, total, x, y);
            #endif
            marks[total].x = x;
            marks[total].y = y;
            total++;
            if (total > size) {
                completed = 1;
                break;
            }
        }
        if(completed) break;
    }
    #if DEBUG
    fprintf(log, "completed %lu\n", total);
    fclose(log);
    #endif
    return total;
}

void * dlib_facemarker_load(const char * path) {
    return new FaceMarker(path);
}
unsigned long dlib_facemarker_run(const void * facemarker, const char * photo_path, const void * buffer, const unsigned long size) {
    FaceMarker * ref = (FaceMarker *)facemarker;
    return ref->run(photo_path, buffer, size);
}
void dlib_facemarker_close(const void * facemarker) {
    FaceMarker * ref = (FaceMarker *)facemarker;
    delete ref;
}