#ifndef PROJECTIONITEMIO_H
#define PROJECTIONITEMIO_H

#include "LFFileFIFF.h"
#include "LFProjectionItem.h"

class LFProjectionItemIO
{
public:
    static returncode_t Read( LFProjectionItem& out, LFFileFIFF& file );
};

#endif
