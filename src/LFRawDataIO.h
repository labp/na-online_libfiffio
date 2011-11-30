#ifndef LFRAWDATAIO_H
#define LFRAWDATAIO_H

#include "LFFileFIFF.h"
#include "LFRawData.h"

class LFRawDataIO
{
public:
    static returncode_t Read( LFRawData& out, LFFileFIFF& file );
};

#endif
