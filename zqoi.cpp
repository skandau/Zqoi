
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

