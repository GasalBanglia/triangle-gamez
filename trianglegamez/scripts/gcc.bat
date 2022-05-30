cd C:\Games\Triangle-Gamez
cd res
windres triangle-gamez.rc ..\obj\triangleRes.o
cd ..\obj
gcc -c ..\src\trianglegamez.c ..\lib\triangleOperations.c 
cd ..
gcc -o bin\triangle-gamez.exe obj\trianglegamez.o obj\triangleOperations.o obj\triangleRes.o -lgdi32 -lwinmm
