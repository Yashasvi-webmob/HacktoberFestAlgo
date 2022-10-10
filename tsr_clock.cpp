/* A TSR CLOCK */

#include "dos.h"

void interrupt ( *prevtimer )( ) ;
void interrupt mytimer( ) ;

int running = 0 ;
unsigned long far *time = ( unsigned long far * ) 0x46C ;
char far *scr ;
char far *mode ;

main( )
{

/* peek into location 0:410h and determine video mode */
if ( ( *mode & 0x30 ) == 0x30 )
     scr = ( char far * ) 0xB0000000 ;
else
     scr = ( char far * ) 0xB8000000 ;

prevtimer = getvect ( 8 ) ;
setvect ( 8, mytimer ) ;
keep ( 0, 1000 ) ;

}

void interrupt mytimer( )
{
  unsigned char hours, sec, min ;

if ( running == 0 )
{

running = 1;
hours = ( *time / 65520 ) ;
min = ( *time - hours * 65520 ) / 1092 ;
sec = ( *time - hours * 65520 - min * 1092 ) * 10 / 182 ;

if ( sec >= 60 )
{

sec -= 60 ;
min++ ;

if ( min == 60 )
{

min = 0 ;
hours++ ;

if ( hours == 24 )
hours = 0 ;

}

}



/* display digital clock */
writechar ( 48 + hours / 10, 0, 72, 112 ) ;
writechar ( 48 + hours % 10, 0, 73, 112 ) ;
writechar ( ':', 0, 74, 112 ) ;
writechar ( 48 + min / 10, 0, 75, 112 ) ;
writechar ( 48 + min % 10, 0, 76, 112 ) ;
writechar ( ':', 0, 77, 112 ) ;
writechar ( 48 + sec / 10, 0, 78, 112 ) ;
writechar ( 48 + sec % 10, 0, 79, 112 ) ;

running = 0 ;

}

      ( *prevtimer )( ) ;

}



writechar ( char ch, int row, int col, int attr )
{

*( scr + row * 160 + col * 2 ) = ch ;
*( scr + row * 160 + col * 2 + 1 ) = attr ;

}
