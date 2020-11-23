cmake_minimum_required(VERSION 3.0.0)
project(mp3meta VERSION 0.1.0)


add_executable(mp3meta src/main.c src/constants.h src/types.h src/types.c src/mp3meta.c src/mp3meta.h src/utils.h src/utils.c src/id3v2lib_utils.c src/id3v2lib_utils.h)

include(CPack)
