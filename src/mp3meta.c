#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "id3v2lib_utils.h"

#include <stdio.h>

ID3v2_header* load_header_from_buffer(char* buffer, int length){
    size_t position = 0;

    if (has_id3_magic(buffer) == 0){
        return NULL;
    }

    ID3v2_header* header;
    header = new_header();

    memcpy(header->tag, buffer, ID3_HEADER_TAG);
    position += ID3_HEADER_TAG;

    header->major_version = buffer[position];
    position+=ID3_HEADER_VERSION;

    header->minor_version = buffer[position];
    position+=ID3_HEADER_VERSION;

    header->flags = buffer[position];
    position+=ID3_HEADER_FLAGS;

    /*
     *  Do not actually need tag_size for minimal functionality,
     *  so just use one from library to see how it looks decoded
     *  (seems way too complex to spend time on reimplementing it)
     */
    printf("position: %d\n", position);
    for (size_t i = position; i <= ID3_HEADER; i++)
    {
        printf("0x%02x ", buffer[i]);
    }
    printf("\n");
    
    header->tag_size = syncint_decode(btoi(buffer, ID3_HEADER, position));

    return header;
}