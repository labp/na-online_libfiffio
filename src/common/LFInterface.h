#ifndef LFINTERFACE_H
#define LFINTERFACE_H

#include "LFData.h"

///Interface
class LFInterface
{
public:
    ///Reads the fiff - file and returns the LFFiffData - Object
    static int fiffRead( LFData& output, const char* path );
};

#endif
