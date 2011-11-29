#ifndef LFHPICOILIO_H
#define LFHPICOILIO_H

#include "LFFileFIFF.h"
#include "LFHPICoil.h"

class LFHPICoilIO
{
public:
    static returncode_t Read( LFHPICoil& out, LFFileFIFF& file );
};

#endif
