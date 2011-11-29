
#include "LFHPIMeasurementIO.h"

returncode_t LFHPIMeasurementIO::Read( LFHPIMeasurement& out, LFFileFIFF& file )
{
    LFElementHeader header;
    returncode_t ret = rc_error_unknown;
    while( ( ret = file.ReadElementHeader( header ) ) == rc_normal )
    {
        switch( header.GetTag() )
        {
            case tag_block_start:
            {
                int32_t block;
                ret = file.Read< int32_t > ( block );
                if( ret != rc_normal )
                    return ret;
                switch( block )
                {
                    case block_hpi_coil:
                    {
                        LFHPICoil& dst=out.GetLFHPICoil().AddNew();
                        ret = LFHPICoilIO::Read( dst, file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_hpi_coil
                    }
                    default:
                        ret = file.SkipBlock();
                        if( ret != rc_normal )
                            return ret;
                        break;
                }
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over
            case tag_sfreq:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetSamplingFrequency( buf );
                break;//tag_sfreq
            }
            case tag_nchan:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetNumberOfChannels( buf );
                break;//tag_nchan
            }
            case tag_nave:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetNumberOfAverages( buf );
                break;//tag_nave
            }
            case tag_hpi_ncoil:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetNumberOfHPICoils( buf );
                break;//tag_hpi_ncoil
            }
            case tag_first_sample:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetFirstSample( buf );
                break;//tag_first_sample
            }
            case tag_last_sample:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetLastSample( buf );
                break;//tag_last_sample
            }
            default:
                file.Skip( header.GetSize() );//Unknown element
                break;
        }
        if(header.GetNext()<0)return ret;
    }
    return ret;
}
