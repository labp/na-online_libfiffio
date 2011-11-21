#include <stdlib.h>
#include <string.h>

#include "./common/LFInterface.h"
#include "LFFileFIFF.h"

#include "LFDataIO.h"

returncode_t LFInterface::fiffRead(LFData& output, const char* path)
{
    LFFileFIFF file;
    returncode_t ret=rc_error_unknown;
    ret=file.OpenRead(path);
    if(ret!=rc_normal)return ret;
    ret=LFDataIO::Read(output,file);
    if(ret!=rc_normal)
    {
        file.Close();
        return ret;
    }
    return file.Close();
}
