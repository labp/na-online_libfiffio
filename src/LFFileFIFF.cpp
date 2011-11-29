#include <unistd.h>

#include "LFFileFIFF.h"

LFFileFIFF::LFFileFIFF() :
    m_file( NULL ), m_next( 0 )
{

}

returncode_t LFFileFIFF::OpenRead( const char* pathname )
{
    m_file = fopen( pathname, "rb" );
    return m_file == NULL ? rc_error_file_open : rc_normal;
}

returncode_t LFFileFIFF::ReadElementHeader( LFElementHeader& out )
{
    if( m_file == NULL )
        return rc_error_unknown;
    if(m_next>0){
        if(fseek(m_file,m_next,SEEK_SET)){
            out.Init();
            return rc_error_file_read;
        }
        m_next=0;
    }
    if( fread( &out.m_tag, sizeof( out.m_tag ), 1, m_file ) != 1 )
    {
        out.Init();
        return rc_error_file_read;
    }
    if( fread( &out.m_type, sizeof( out.m_type ), 1, m_file ) != 1 )
    {
        out.Init();
        return rc_error_file_read;
    }
    if( fread( &out.m_size, sizeof( out.m_size ), 1, m_file ) != 1 )
    {
        out.Init();
        return rc_error_file_read;
    }
    if( fread( &out.m_next, sizeof( out.m_next ), 1, m_file ) != 1 )
    {
        out.Init();
        return rc_error_file_read;
    }
    swab( out.m_tag );
    swab( out.m_type );
    swab( out.m_size );
    swab( out.m_next );
    m_next=out.m_next;
    return rc_normal;
}

returncode_t LFFileFIFF::ReadString( char* out, int32_t length )
{
    if( m_file == NULL || out == NULL )
        return rc_error_unknown;
    return fread( out, length, 1, m_file ) == 1 ? rc_normal : rc_error_file_read;
}

returncode_t LFFileFIFF::ReadArrayFloat( float* out, int32_t bytes )
{
    if( m_file == NULL || out == NULL )
        return rc_error_unknown;
    if( fread( out, bytes, 1, m_file ) != 1 )
        return rc_error_file_read;
    int32_t sz = bytes / sizeof(float);
    for( int32_t i = 0; i < sz; i++ )
        swab( out[i] );
    return rc_normal;
}

returncode_t LFFileFIFF::Skip( int32_t bytes )
{
    if( m_file == NULL )
        return rc_error_unknown;
    return fseek( m_file, bytes, SEEK_CUR) ? rc_error_file_read : rc_normal;
}

returncode_t LFFileFIFF::SkipBlock()
{
    LFElementHeader header;
    returncode_t ret = rc_error_unknown;
    unsigned int started_blocks = 1;
    while( ( ret = ReadElementHeader( header ) ) == rc_normal )
    {
        switch( header.GetTag() )
        {
            case tag_block_start:
                started_blocks++;
                break;
            case tag_block_end:
                started_blocks--;
                break;
        }
        ret = Skip( header.GetSize() );
        if( !started_blocks || ret != rc_normal )
            return ret;
    }
    return ret;
}

returncode_t LFFileFIFF::Close()
{
    returncode_t ret = rc_error_unknown;
    if( m_file != NULL )
    {
        if( !fclose( m_file ) )
            ret = rc_normal;
        m_file = NULL;
    }
    return ret;
}
