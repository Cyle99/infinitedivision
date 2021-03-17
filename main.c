#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main ( int argc, char *argv[] )
{

    int dividend = 0;
    int divisor = 0;
    int limit = 0;

    if ( argc < 3 ) {
        printf ( "Not enough arguments.\n" );
        return 1;
    }  else if ( argc > 4 ) {
        printf ( "Too many arguments.\n" );
        return 1;
    } else {
        dividend = atoi ( argv[1] );
        divisor = atoi ( argv[2] );

        if ( argc == 4 ) {
            limit = atoi ( argv[3] );
        }
    }

    printf ( "%d / %d = ", dividend, divisor );

    if ( !divisor ) {
        printf ( "undefined\n" );
        return 0;
    }

    int rest = 0;
    char decimal = 0;
    char limitless = limit;

    if ( dividend < divisor ) {
        printf ( "0" );
    }

    fflush ( stdout );

    do {
        if ( dividend < divisor ) {
            if ( !decimal ) {
                printf ( "." );
                decimal = 1;
                fflush ( stdout );
                usleep ( 100000 );
            }

            dividend *= 10;
        }

        rest = dividend % divisor;
        printf ( "%d",  dividend / divisor );
        dividend = rest;
        fflush ( stdout );

        if ( limitless && !limit-- ) {
            break;
        }

        usleep ( 100000 );
    } while ( rest );

    printf ( "\n" );

    return 0;
}