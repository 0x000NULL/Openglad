
//
// util.h
//
// misc helper functions, and timer
//
#ifndef _UTIL_H__
#define _UTIL_H__

#include "SDL.h"
#include <ctype.h>
#include <string>

#include "io.h"

void Log(const char* format, ...);

void change_time(Uint32 new_count);

void grab_timer();
void release_timer();
void reset_timer();
Sint32 query_timer();
Sint32 query_timer_control();
void time_delay(Sint32);

// Zardus: add: lowercase func
void lowercase(char *);

// kari: lowercase for std::strings
void lowercase(std::string &);

//buffers: add: uppercase func
void uppercase(char *);

// kari: uppercase for std::strings
void uppercase(std::string &);

// Zardus: add: set_mult func
void set_mult(int);

#endif
