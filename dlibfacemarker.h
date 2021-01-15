#ifndef __DLIB_FACE_MARKER__
#define __DLIB_FACE_MARKER__

#ifdef __cplusplus
extern "C" {
#endif

extern void * dlib_facemarker_load(const char * path);
extern int dlib_facemarker_run(const void * facemarker, const char * photo_path, int * marks);
extern void dlib_facemarker_close(const void * facemarker);
#ifdef __cplusplus
}
#endif

#endif //__DLIB_FACE_MARKER__