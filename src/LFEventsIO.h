#ifndef LFEVENTSIO_H
#define LFEVENTSIO_H

#include "LFFileFIFF.h"
#include "LFEvents.h"

class LFEventsIO
{
public:
    static returncode_t Read( LFEvents& out, LFFileFIFF& file );
};

#endif
