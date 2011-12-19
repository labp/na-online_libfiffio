#ifndef LFHPISUBSYSTEMIO_H
#define LFHPISUBSYSTEMIO_H

#include "LFFileFIFF.h"
#include "LFHPISubsystem.h"

class LFHPISubsystemIO
{
public:
    static returncode_t Read( LFHPISubsystem& out, LFFileFIFF& file );
};

#endif
