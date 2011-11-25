#ifndef LFHPICOILIO_H
#define LFHPICOILIO_H

#include "LFFileFIFF.h"
#include "LFHPICoil.h"

class LFHPICoilIO
{
public:
//    static bool Read( LFArrayPtr<LFHPICoil>& out, fiffDirNode parentdirnode, fiffFile& file );
    static returncode_t Read( LFHPICoil& out, LFFileFIFF& file );
};

#endif
