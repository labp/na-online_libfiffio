#ifndef LFHPIMEASUREMENTIO_H
#define LFHPIMEASUREMENTIO_H

#include "LFFileFIFF.h"
#include "LFHPIMeasurement.h"
#include "LFHPICoilIO.h"

class LFHPIMeasurementIO
{
public:
    static returncode_t Read( LFHPIMeasurement& out, LFFileFIFF& file );
};

#endif
