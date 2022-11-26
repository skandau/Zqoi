set incs=-DNDEBUG -DWIN32 -D_FILE_OFFSET_BITS=64 -I. -Dmalloc_trim(x)=

set opts=-Wnarrowing -fomit-frame-pointer -fpermissive -fno-stack-protector -fno-stack-check
set gcc=C:\MinGW\mingw\bin\g++.exe -m64 -march=k8
set path=%gcc%\..\

%gcc% -std=gnu++1z -O3 -s %incs% %opts% -static zqoi.cpp libzpaq.cpp  -o zqoi.exe

pause