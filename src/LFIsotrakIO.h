#ifndef LFISOTRAKIO_H
#define LFISOTRAKIO_H

#include "LFFileFIFF.h"
#include "LFIsotrak.h"

class LFIsotrakIO
{
public:
    static returncode_t Read( LFIsotrak& out, LFFileFIFF& file );
};

#endif
