#ifndef ACONV_H_
#define ACONV_H_

// definitions:
#define FS 44100
#define BITDEPTH 16
//#define OFFLINE_BUFN FS * 60 * 60 * 3    // 3 hours
#define OFFLINE_BUFN FS * 10    // 10 seconds
#define ONLINE_BUFN 512
#define CHNN 2

// includes:
#include "atime.h"
#include "aout.h"
#include "singl.h"

#endif
