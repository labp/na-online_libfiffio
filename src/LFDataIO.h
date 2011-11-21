#ifndef LFDATAIO_H
#define LFDATAIO_H

#include "LFFileFIFF.h"
#include "LFData.h"
#include "LFMeasurementIO.h"

class LFDataIO
{
public:
    static returncode_t Read( LFData& out, LFFileFIFF& file );
};
#endif
