#ifndef LFPROJECTIO_H
#define LFPROJECTIO_H

#include <memory.h>

#include "LFFileFIFF.h"
#include "LFProject.h"

class LFProjectIO
{
public:
    static returncode_t Read( LFProject& out, LFFileFIFF& file );
};

#endif
