#ifndef LFMEASUREMENTIO_H
#define LFMEASUREMENTIO_H

#include "LFFileFIFF.h"
#include "LFMeasurement.h"
#include "LFMeasurementInfoIO.h"

class LFMeasurementIO
{
public:
    static returncode_t Read( LFMeasurement& out, LFFileFIFF& file );
};

#endif
