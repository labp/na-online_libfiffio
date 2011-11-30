#include "LFMeasurementIO.h"

returncode_t LFMeasurementIO::Read( LFMeasurement& out, LFFileFIFF& file )
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
                    case block_meas_info:
                        ret = LFMeasurementInfoIO::Read( out.GetLFMeasurementInfo(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_meas_info
                    case block_raw_data:
                        ret = LFRawDataIO::Read( out.GetLFRawData(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_raw_data
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
            case tag_bem_coord_frame:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetBemCoordinateFrame( ( LFMeasurement::coord_t )buf );
                break;
            }
            default:
                file.Skip( header.GetSize() );//Unknown element
                break;
        }
        if(header.GetNext()<0)return ret;
    }
    return ret;
}
