#ifndef mp3meta_types_h
#define mp3meta_types_h

#include "constants.h"

typedef struct
{
    char tag[ID3_HEADER_TAG_SIZE];
    char major_version;
    char minor_version;
    char flags;
    int tag_size;
} ID3v2_header;

ID3v2_header* new_header();
int has_id3_magic(char* raw_header);
int has_id3v2_header(ID3v2_header* header);

#endif