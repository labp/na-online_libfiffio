#ifndef LFFILEFIFF_H
#define LFFILEFIFF_H

#include "LFElementHeader.h"

/**
 * Operations with the FIFF - file
 */
class LFFileFIFF
{
protected:
    FILE* m_file;/**< File header */
    int32_t m_next;/**< The position of the next element to read */
public:
    /**
     * Makes class T little endian
     */
    template< class T > static void swab( T& var );
    /**
     * Constructor
     */
    LFFileFIFF();
    /**
     * Opens the file for reading
     */
    returncode_t OpenRead( const char* pathname );
    /**
     * Reads the FIFF - element header
     */
    returncode_t ReadElementHeader( LFElementHeader& out );
    /**
     * Reads a string
     */
    returncode_t ReadString( char* out, int32_t length );
    /**
     * Skips bytes in the file
     */
    returncode_t Skip( int32_t bytes );
    /**
     * Skips the block and all its content
     */
    returncode_t SkipBlock();
    /**
     * Reads the class T value
     */
    template< class T > returncode_t Read( T& out );
    /**
     * Closes the FIFF - file
     */
    returncode_t Close();
};

template< class T > void LFFileFIFF::swab( T& var )
{
    int sz = sizeof( var ) / 2;
    for( int i = 0; i < sz; i++ )
    {
        char c = ( ( char* )&var )[i];
        char* end = ( ( char* )&var ) + ( sizeof( var ) - i ) - 1;
        ( ( char* )&var )[i] = *end;
        *end = c;
    }
}

template< class T > returncode_t LFFileFIFF::Read( T& out )
{
    if( m_file == NULL )
        return rc_error_unknown;
    if( fread( &out, sizeof( out ), 1, m_file ) != 1 )
        return rc_error_file_read;
    swab( out );
    return rc_normal;
}

#endif //LFFILEFIFF_H
