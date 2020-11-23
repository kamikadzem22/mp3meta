#include <stdlib.h>
#include <string.h>

#include "types.h"


ID3v2_header* new_header() {
    ID3v2_header* header = (ID3v2_header*) malloc(sizeof(ID3v2_header));
    if (header != NULL) {
        memset(header->tag, '\0', ID3_HEADER_TAG);
        header->tag[ID3_HEADER_TAG] = '\0';

        header->major_version = 0x00;
        header->minor_version = 0x00;
        header->flags = 0x00;
        
    }

    return header;
}

int has_id3_magic(char* raw_header){
    const char* id3_magic = "ID3";
    return strncmp(raw_header, id3_magic, 3) == 0 ? 1 : 0;
}

int has_id3v2_header(ID3v2_header* header){
    return (header->major_version == 2) ? 1 : 0;
}