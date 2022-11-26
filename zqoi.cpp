/* demo1.cpp - Demo file compressor for libzpaq.

Written by Matt Mahoney, Sept. 27, 2010.
This program is placed in the public domain.
It is provided "as is" with no warranty.

To use: demo1 command input output
Commands:
  1 = compress fast
  2 = compress medium
  3 = compress best
  d = decompress

For example, to compress the file book1:

  demo1 3 book1 book1.zpaq
  demo1 d book1.zpaq book1

To compile with g++, Borland, or Mars:

  g++ -O2 demo1.cpp libzpaq.cpp -o demo1
  bcc32 -O -6 demo1.cpp libzpaq.cpp
  dmc -o -6 demo1.cpp libzpaq.cpp

Use option -DNDEBUG to turn off run time checks for more speed.
Use other optimization options as appropriate for your platform.
These are just examples.
*/

#include <stdio.h>
#include <stdlib.h>

// libzpaq required functions: get(), put(), and error()
namespace libzpaq {

  inline int get(FILE* in) {
    int c=getc(in);
    return c==EOF?-1:c;
  }

  inline void put(int c, FILE* out) {
    putc(c, out);
  }

  void error(const char* msg) {
    fprintf(stderr, "libzpaq error: %s\n", msg);
    exit(1);
  }
}

#include "libzpaq.h"

// File compressor and decompresser
int main(int argc, char** argv) {

  // Print help message
  if (argc<=3) {
    printf("To compress file: zqoi cmd input(.png/.zqoi) step1(.qoi) output(.zqoi) \n"
      "To decompress file: zqoi d input(.zqoi) output(.qoi) \n"
	  "Commands: 1=compress, d=decompress\n"
	  );
    return 1;
  }
char temp[512];
char temp1[512];

char cmd=argv[1][0];

  // Compress
  if (cmd>='1' && cmd<='3')
  { 
  FILE* in=fopen(argv[3], "rb");
  FILE* out=fopen(argv[4], "wb"); 

    sprintf(temp, "d:\\qoiconv.exe %s %s", argv[2], argv[3]);
    system((char *)temp); 

    libzpaq::compress(in, out, cmd-'0');
  
   }



  // Decompress
  else if (cmd =='d')
  {
      FILE* inx=fopen(argv[2], "rb");
      FILE* outx=fopen(argv[3], "wb");

       libzpaq::decompress(inx, outx); 
  

//       sprintf(temp1, "d:\\qoiconv.exe %s %s",outx,argv[4] );
//       system((char *)temp1); 
      

 
   }

      
    
}

