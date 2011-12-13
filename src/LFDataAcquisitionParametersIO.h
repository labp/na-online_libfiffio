#ifndef LFDATAACQUISITIONPARAMETERSIO_H
#define LFDATAACQUISITIONPARAMETERSIO_H

#include "LFFileFIFF.h"
#include "LFDataAcquisitionParameters.h"

class LFDataAcquisitionParametersIO
{
public:
    static returncode_t Read( LFDataAcquisitionParameters& out, LFFileFIFF& file );
};

#endif
