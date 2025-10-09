/*
 * SPDX-FileCopyrightText: Copyright (C) 2025 Altera Corporation
 *
 * SPDX-License-Identifier: MIT-0
 *
 * Low level driver hooks for standard library
 */

#include <sys/stat.h>
#include <unistd.h>
#include <socfpga_console.h>
#include <FreeRTOSConfig.h>

static size_t remaining_heap;
static size_t smallest_ever_remaining_heap;

int _close( int file )
{
    ( void ) file;
    return -1;
}
/*-----------------------------------------------------------*/

int _fstat( int file,
            struct stat * st )
{
    ( void ) file;
    st->st_mode = S_IFCHR;
    return 0;
}
/*-----------------------------------------------------------*/

int _isatty( int file )
{
    ( void ) file;
    return 1;
}
/*-----------------------------------------------------------*/

int _lseek( int file,
            int ptr,
            int dir )
{
    ( void ) file;
    ( void ) ptr;
    ( void ) dir;
    return 0;
}
/*-----------------------------------------------------------*/

int _read( int file,
           char * ptr,
           int len )
{
    ( void ) file;
    ( void ) ptr;
    ( void ) len;

    console_read( ( unsigned char * const ) ptr, 1 );
    return 1;
}
/*-----------------------------------------------------------*/

int _write( int file,
            const char * ptr,
            int len )
{
    ( void ) file;
    console_write( ( unsigned char * const ) ptr, len );

    return len;
}
/*-----------------------------------------------------------*/

int _kill( int pid,
           int sig )
{
    ( void ) pid;
    ( void ) sig;
    return 0;
}
/*-----------------------------------------------------------*/

int _getpid( void )
{
    return 1;
}
/*-----------------------------------------------------------*/

int atexit( void ( * )( void ) )
{
    return 0;
}
/*-----------------------------------------------------------*/

void exit( int rc )
{
    ( void ) rc;

    while( 1 )
    {
    }
}
/*-----------------------------------------------------------*/

void * _sbrk( ptrdiff_t incr )
{
extern char end;       /* Set by linker.  */
extern char _heap_end; /* Set by linker */
static char * heap_end;
char * prev_heap_end;

    if( heap_end == 0 )
    {
        /*Init the heap */
        heap_end = &end;
        remaining_heap = &_heap_end - &end;
        smallest_ever_remaining_heap = remaining_heap;
    }

    if( ( heap_end + incr ) >= &_heap_end )
    {
        prev_heap_end = NULL;
    }
    else
    {
        prev_heap_end = heap_end;
        heap_end += incr;
        remaining_heap -= incr;

        if( smallest_ever_remaining_heap > remaining_heap )
        {
            smallest_ever_remaining_heap = remaining_heap;
        }
    }

    return ( void * ) prev_heap_end;
}
/*-----------------------------------------------------------*/

size_t get_remaining_heap_size()
{
    return remaining_heap;
}
/*-----------------------------------------------------------*/

size_t get_smallest_ever_remaining_heap_size()
{
    return smallest_ever_remaining_heap;
}
/*-----------------------------------------------------------*/
