#ifndef LFSUBJECTIO_H
#define LFSUBJECTIO_H

#include <memory.h>

#include "LFFileFIFF.h"
#include "LFSubject.h"

class LFSubjectIO
{
public:
    static returncode_t Read( LFSubject& out, LFFileFIFF& file );
};

#endif
