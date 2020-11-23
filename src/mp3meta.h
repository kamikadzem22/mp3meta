#ifndef mp3meta_h
#define mp3meta_h

#include "types.h"

ID3v2_header* load_header_from_buffer(char* bytes, int length);
#endif