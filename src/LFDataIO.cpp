#include "LFDataIO.h"

returncode_t LFDataIO::Read( LFData& out, LFFileFIFF& file )
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
                switch( block )
                {
                    case block_meas:
                        ret = LFMeasurementIO::Read( out.GetLFMeasurement(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_meas
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
            default:
                file.Skip( header.GetSize() );
                break;
        }
        if(header.GetNext()<0)return ret;
    }
    return ret;
}
