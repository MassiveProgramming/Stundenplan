#include "fileparser.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

FileParser::FileParser()
{
    file_contents = NULL;
}

void FileParser::loadFile( char *path )
{
    FILE * pFile;
    char * buffer;
    size_t result;

    if ( file_contents != NULL ) {
        free( file_contents );
    }

    pFile = fopen( path , "rb" );
    if ( pFile == NULL ) {
        fprintf( stderr, "File error %s", path );
        exit( 1 );
    }

    fseek( pFile , 0 , SEEK_END );
    file_size = ftell( pFile );
    rewind( pFile );

    buffer = (char*) malloc( sizeof(char) * file_size );
    if (buffer == NULL) {
        fputs( "Memory error", stderr );
        exit( 2 );
    }

    result = fread( buffer, 1, file_size, pFile );
    if ( result != file_size ) {
        fputs( "Reading error", stderr );
        exit( 3 );
    }

    file_contents = buffer;

    fclose( pFile );
}

struct tag FileParser::parseFile()
//void FileParser::parseFile()
{
    p = file_contents;
    struct tag t;
    t.name = parseString( ' ' );
    t.std = ( struct stunde * ) malloc( sizeof( struct stunde ) * 11 );
    memset( t.std, 0, sizeof( struct stunde ) * 11 );
    t.stunden = 0;
    skip();
    skip( '{' );
    while ( *p != '}' && p < file_contents + file_size ) {
        skip();
        if ( *p == '}' ) {
            break;
        }
        t.std[ t.stunden ] = parseStunde();
        //printf( "%s,%s,%s\n", t.std[ t.stunden ].fach, t.std[ t.stunden ].lehrer, t.std[ t.stunden ].raum );
        t.stunden++;
    }
    return t;
    //return;
}

struct stunde FileParser::parseStunde()
{
    struct stunde st;
    st.fach = parseString( ',' );
    skip( ',' );
    st.lehrer = parseString( ',' );
    skip( ',' );
    st.raum = parseString( ';' );
    skip( ';' );
    return st;
}

char *FileParser::parseString( char term )
{
    char *start = p;
    char *end;
    while ( *p != term && p < file_contents + file_size ) {
        p++;
    }
    if ( *p == term ) {
        end = p;
    } else {
        fprintf( stderr, "End of File\n" );
        return ( char* ) "END OF FILE";
    }
    char *string = ( char* ) malloc( end - start );
    memset( string, 0, end - start );
    strncat( string, start, end - start );
    strcat( string, "" );
    return string;
}

void FileParser::skip()
{
    while ( ( *p == ' ' || *p == '\n' || *p == '\t' ) && p < file_contents + file_size ) {
        p++;
    }
}

bool FileParser::skip( char c )
{
    if ( *p == c ) {
        p++;
        return true;
    }
    return false;
}
