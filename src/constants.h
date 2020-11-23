#ifndef mp3meta_constants_h
#define mp3meta_constants_h

/**
 *  ID3v2_header size constants
 *  Size relative to file structure size 
 */
#define ID3_HEADER 10
#define ID3_HEADER_TAG 3
#define ID3_HEADER_VERSION 1
#define ID3_HEADER_REVISION 1
#define ID3_HEADER_FLAGS 4

// size to place a null terminator in struct
#define ID3_HEADER_SIZE ID3_HEADER + 1
#define ID3_HEADER_TAG_SIZE ID3_HEADER_TAG + 1
#define ID3_HEADER_FLAGS_SIZE ID3_HEADER_FLAGS + 1




#endif