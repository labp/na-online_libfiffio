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
                    case block_isotrak:
                        ret = LFIsotrakIO::Read( out.GetLFIsotrak(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_isotrak
                    case block_xfit_proj:
                        ret = LFSSPIO::Read( out.GetLFSSP(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_xfit_proj
                    case block_events:
                        ret = LFEventsIO::Read( out.GetLFEvents(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_events
                    case block_dacq_pars:
                        ret = LFDataAcquisitionParametersIO::Read( out.GetLFDataAcquisitionParameters(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_dacq_pars
                    case block_hpi_subsystem:
                        ret = LFHPISubsystemIO::Read( out.GetLFHPISubsystem(), file );
                        if( ret != rc_normal )
                            return ret;
                        break; //block_hpi_subsystem
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
                break;//tag_gantry_angle
            }
            case tag_ch_info:
            {
                int32_t buf_int;
                float buf_float;
                int32_t sz = header.GetSize();
                LFChannelInfo& dst = out.GetLFChannelInfo().AddNew();
                ret = file.Read< int32_t > ( buf_int );
                if( ret != rc_normal )
                    return ret;
                dst.SetScanNo( buf_int );
                ret = file.Read< int32_t > ( buf_int );
                if( ret != rc_normal )
                    return ret;
                dst.SetLogNo( buf_int );
                ret = file.Read< int32_t > ( buf_int );
                if( ret != rc_normal )
                    return ret;
                dst.SetKind( buf_int );
                ret = file.Read< float > ( buf_float );
                if( ret != rc_normal )
                    return ret;
                dst.SetRange( buf_float );
                ret = file.Read< float > ( buf_float );
                if( ret != rc_normal )
                    return ret;
                dst.SetCal( buf_float );
                ret = file.Read< int32_t > ( buf_int );
                if( ret != rc_normal )
                    return ret;
                dst.SetCoilType( buf_int );
                ret = file.ReadArrayFloat( dst.GetR0(), sizeof(float) * 3 );
                if( ret != rc_normal )
                    return ret;
                ret = file.ReadArrayFloat( dst.GetEx(), sizeof(float) * 3 );
                if( ret != rc_normal )
                    return ret;
                ret = file.ReadArrayFloat( dst.GetEy(), sizeof(float) * 3 );
                if( ret != rc_normal )
                    return ret;
                ret = file.ReadArrayFloat( dst.GetEz(), sizeof(float) * 3 );
                if( ret != rc_normal )
                    return ret;
                ret = file.Read< int32_t > ( buf_int );
                if( ret != rc_normal )
                    return ret;
                dst.SetUnit( ( fiffunits_t )buf_int );
                ret = file.Read< int32_t > ( buf_int );
                if( ret != rc_normal )
                    return ret;
                dst.SetUnitMul( ( fiffmultipliers_t )buf_int );
                file.Skip( sz - 80 );//Unknown data
//                                unsigned char* p=new unsigned char[sz];//dbg
//                                file.ReadString((char*)p,sz);//dbg
//                                for(int32_t i=0; i<sz; i++)printf("%x ",p[i]);//dbg
//                                printf("\n");//dbg
                break;//tag_ch_info
            }
            case tag_bad_chs:
            {
                vector< int32_t >& dst = out.GetBadChannels();
                size_t sz = header.GetSize();
                dst.resize( sz / sizeof(int32_t) );
                ret = file.ReadArrayInt32( ( int32_t* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break; //tag_bad_chs
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
