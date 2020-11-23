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

#ifndef id3v2lib_utils_h
#define id3v2lib_utils_h

unsigned int btoi(char* bytes, int size, int offset);
char* itob(int integer);
int syncint_encode(int value);
int syncint_decode(int value);

#endif
