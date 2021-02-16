#ifndef __DLIB_FACE_MARKER__
#define __DLIB_FACE_MARKER__

#ifdef __cplusplus
extern "C" {
#endif

extern void * dlib_facemarker_load(const char * path);
extern unsigned long dlib_facemarker_run(const void * facemarker, const char * photo_path, const void * buffer, const unsigned long size);
extern void dlib_facemarker_close(const void * facemarker);
#ifdef __cplusplus
}
#endif

#endif //__DLIB_FACE_MARKER__
