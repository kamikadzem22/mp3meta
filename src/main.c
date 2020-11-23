#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "constants.h"
#include "mp3meta.h"

void test_parse_header_struct(char* filename){
    char *buffer;
    FILE* mp3file;

    mp3file = fopen(filename, "rb");
    if (mp3file == NULL){
        perror("Error opening file\n");
        exit(-1);
    }
    printf("File handler address %p\n", mp3file);

    buffer = (char*) malloc(ID3_HEADER_SIZE * sizeof(char));
      if(buffer == NULL) {
        perror("Could not allocate buffer");
        fclose(mp3file);
        exit(-1);
    }

    fread(buffer, ID3_HEADER, 1, mp3file);
    fclose(mp3file);


    ID3v2_header* header;
    header = load_header_from_buffer(buffer, ID3_HEADER);
    if (header == NULL){
        perror("Does no have ID3 magic!");
        exit(-1);
    }
    free(buffer);

    printf("Is ID3v2 header? %s\n", has_id3v2_header(header) ? "Yes" : "No");

    printf("header: %s\n", header->tag);
    printf("major %d minor %d\n", header->major_version, header->minor_version);
    printf("tag_size: %d\n", header->tag_size);

    free(header);

}

// void test_parse_header(char* filename){
//     struct id3v2struct metadata_struct;
//     FILE* mp3file;
//     mp3file = fopen(filename, "rb");
//     if (mp3file == NULL){
//         printf("Error opening file\n");
//         exit(-1);
//     }
//     printf("File handler address %p\n", mp3file);


//     fread(&metadata_struct, sizeof(struct id3v2struct), 1, mp3file);
//     printf("Major: 0x%02x Revision: 0x%02x\n", metadata_struct.major_version, metadata_struct.revision_version);
//     printf("Unsynchronisaion used: 0x%02x\n", metadata_struct.unsynchronisaion_used);
//     printf("Compression used: 0x%02x\n", metadata_struct.compression_used);
//     printf("Tag size: %u\n", metadata_struct.tag_size);
//     fseek(mp3file, 0, SEEK_SET);
//     fread(&metadata_struct.header_data, sizeof(char), 10, mp3file);
//     for (size_t i = 0; i < 10; i++)
//     {
//         metadata_struct.header_data[i] = metadata_struct.header_data[i] == '\x00' ? '_' : metadata_struct.header_data[i];
//     }
//     metadata_struct.header_data[10] = 0;    
//     printf("Header 10 bytes: %s\n", metadata_struct.header_data);
//     fclose(mp3file);
// }

int main(){
    test_parse_header_struct("sample.mp3");
    return 0;
}