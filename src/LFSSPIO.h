#ifndef LFSSPIO_H
#define LFSSPIO_H

#include "LFFileFIFF.h"
#include "LFSSP.h"
#include "LFProjectionItemIO.h"

class LFSSPIO
{
public:
    static returncode_t Read( LFSSP& out, LFFileFIFF& file );
};

#endif
