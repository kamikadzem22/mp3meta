/*
 * This file is part of the id3v2lib library
 *
 * Copyright (c) 2013, Lorenzo Ruiz
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 * 
 * https://github.com/larsbs/id3v2lib
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

unsigned int btoi(char* bytes, int size, int offset)
{
    unsigned int result = 0x00;
    int i = 0;
    for(i = 0; i < size; i++)
    {
        result = result << 8;
        result = result | (unsigned char) bytes[offset + i];
    }
    
    return result;
}

char* itob(int integer)
{
    int i;
    int size = 4;
    char* result = (char*) malloc(sizeof(char) * size);
    
    // We need to reverse the bytes because Intel uses little endian.
    char* aux = (char*) &integer;
    for(i = size - 1; i >= 0; i--)
    {
        result[size - 1 - i] = aux[i];
    }
    
    return result;
}

int syncint_encode(int value)
{
    int out, mask = 0x7F;
    
    while (mask ^ 0x7FFFFFFF) {
        out = value & ~mask;
        out <<= 1;
        out |= value & mask;
        mask = ((mask + 1) << 8) - 1;
        value = out;
    }
    
    return out;
}

int syncint_decode(int value)
{
    unsigned int a, b, c, d, result = 0x0;
    a = value & 0xFF;
    b = (value >> 8) & 0xFF;
    c = (value >> 16) & 0xFF;
    d = (value >> 24) & 0xFF;
    
    result = result | a;
    result = result | (b << 7);
    result = result | (c << 14);
    result = result | (d << 21);
    
    return result;
}
