#ifndef LFBEMIO_H
#define LFBEMIO_H

#include "LFFileFIFF.h"
#include "LFBem.h"

class LFBemIO
{
public:
    static returncode_t Read( LFBem& out, LFFileFIFF& file );
};

#endif
