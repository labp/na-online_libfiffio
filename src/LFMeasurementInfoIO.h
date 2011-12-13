#ifndef LFMEASUREMENTINFOIO_H
#define LFMEASUREMENTINFOIO_H

#include "LFFileFIFF.h"
#include "LFMeasurementInfo.h"
#include "LFSubjectIO.h"
#include "LFProjectIO.h"
#include "LFHPIMeasurementIO.h"
#include "LFIsotrakIO.h"
#include "LFSSPIO.h"
#include "LFEventsIO.h"
#include "LFDataAcquisitionParametersIO.h"

class LFMeasurementInfoIO
{
public:
    static returncode_t Read( LFMeasurementInfo& out, LFFileFIFF& file );
};

#endif
