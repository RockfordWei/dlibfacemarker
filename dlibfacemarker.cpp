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
    unsigned long run(const char * photo_path, unsigned long * marks);
};

FaceMarker::FaceMarker(const char * model_path) {
    deserialize(model_path) >> sp;
}

unsigned long FaceMarker::run(const char * photo_path, unsigned long * marks) {
    array2d<rgb_pixel> img;
    load_image(img, photo_path);
    // Make the image larger so we can detect small faces.
    pyramid_up(img);
    std::vector<rectangle> dets = this->detector(img);
    unsigned long total = 0;
    for (unsigned long j = 0; j < dets.size(); ++j)
    {
        full_object_detection shape = sp(img, dets[j]);
        for(unsigned long i = 0; i < shape.num_parts(); i++) {
            point p = shape.part(i);
            XY * xy = (XY *)(marks + total);
            xy->x = p.x();
            xy->y = p.y();
            total++;
        }
    }
    return total;
}

void * dlib_facemarker_load(const char * path) {
    return new FaceMarker(path);
}
unsigned long dlib_facemarker_run(const void * facemarker, const char * photo_path, unsigned long * marks) {
    FaceMarker * ref = (FaceMarker *)facemarker;
    return ref->run(photo_path, marks);
}
void dlib_facemarker_close(const void * facemarker) {
    FaceMarker * ref = (FaceMarker *)facemarker;
    delete ref;
}