
#include <memory.h>
#include "LFHPICoilIO.h"

returncode_t LFHPICoilIO::Read( LFHPICoil& out, LFFileFIFF& file )
{
    LFElementHeader header;
    returncode_t ret = rc_error_unknown;
    while( ( ret = file.ReadElementHeader( header ) ) == rc_normal )
    {
        switch( header.GetTag() )
        {
            case tag_block_start:
            {
//                int32_t block;
//                ret = file.Read< int32_t > ( block );
//                if( ret != rc_normal )
//                    return ret;
//                switch( block )
//                {
//                   default:
                ret = file.SkipBlock();
                if( ret != rc_normal )
                    return ret;
//                }
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over

            case tag_hpi_coil_no:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetCoilNumber( buf );
                 break;//tag_hpi_coil_no
            }
            case tag_epoch:
            {
                int32_t sz=header.GetSize();
                LFArrayFloat2d & dst=out.GetEpoch();
                dst.AllocateBytes(sz);
                ret = file.ReadArrayFloat( ( float* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break;//tag_epoch
            }
            case tag_hpi_slopes:
            {
                int32_t sz = header.GetSize();
                vector< float >& dst = out.GetSlopes();
                dst.resize( sz / sizeof(float) );
                ret = file.ReadArrayFloat( ( float* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break;//tag_hpi_slopes
            }
            case tag_hpi_corr_coeff:
            {
                int32_t sz = header.GetSize();
                vector< float >& dst = out.GetCorrelationCoefficient();
                dst.resize( sz / sizeof(float) );
                ret = file.ReadArrayFloat( ( float* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break;//tag_hpi_corr_coeff
            }
            case tag_hpi_coil_freq:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetCoilFrequency( buf );
                 break;//tag_hpi_coil_freq
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
