
#include "LFDataAcquisitionParametersIO.h"

returncode_t LFDataAcquisitionParametersIO::Read( LFDataAcquisitionParameters& out, LFFileFIFF& file )
{
    LFElementHeader header;
    returncode_t ret = rc_error_unknown;
    while( ( ret = file.ReadElementHeader( header ) ) == rc_normal )
    {
        switch( header.GetTag() )
        {
            case tag_block_start:
            {
                ret = file.SkipBlock();
                if( ret != rc_normal )
                    return ret;
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over
            case tag_dacq_pars:
            {
                int32_t sz = header.GetSize();
                string& dst = out.GetDAcqPars();
                dst.resize( sz );
                ret = file.ReadString( ( char* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break; //tag_dacq_pars
            }
            case tag_dacq_stim:
            {
                int32_t sz = header.GetSize();
                string& dst = out.GetDAcqStim();
                dst.resize( sz );
                ret = file.ReadString( ( char* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break; //tag_dacq_stim
            }
            default:
                ret=file.Skip( header.GetSize() );
                if( ret != rc_normal )
                    return ret;
                break;
        }
        if(header.GetNext()<0)return ret;
    }
    return ret;
}
