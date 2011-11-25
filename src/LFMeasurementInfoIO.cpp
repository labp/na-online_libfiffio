#include "LFMeasurementInfoIO.h"

returncode_t LFMeasurementInfoIO::Read( LFMeasurementInfo& out, LFFileFIFF& file )
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
                    case block_subject:
                        ret = LFSubjectIO::Read( out.GetLFSubject(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_subject
                    case block_project:
                        ret = LFProjectIO::Read( out.GetLFProject(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_project
                    case block_hpi_meas:
                        ret=LFHPIMeasurementIO::Read(out.GetLFHPIMeasurement(),file);
                        if(ret!=rc_normal)return ret;
                        break;//block_hpi_meas
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
            case tag_nchan:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetNumberOfChannels( buf );
                break;//tag_nchan
            }
            case tag_sfreq:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetSamplingFrequency( buf );
                break;//tag_sfreq
            }
            case tag_lowpass:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetLowpass( buf );
                break;//tag_lowpass
            }
            case tag_highpass:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetHighpass( buf );
                break;//tag_highpass
            }
            case tag_data_pack:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetDataPack( buf );
                break;//tag_data_pack
            }
            case tag_line_freq:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetLineFreq( buf );
                break;//tag_line_freq
            }
            case tag_gantry_angle:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetGantryAngle( buf );
                break;//tag_data_pack
            }
                //            case tag_gantry_angle:
                //            {
                //                vector< int32_t >& dst=out.GetBadChannels();
                //                size_t sz=header.GetSize()/sizeof(int32_t);
                //                dst.resize(sz);
                //            for(size_t i=0; i<sz; i++)dst[i]=*( ( const int32_t* )tag.data );//alte Version
                //                break;//tag_bad_chs
                //            }
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
