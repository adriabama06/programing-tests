cd src
g++ -c *.cpp
g++ -o ..\program.exe *.o
del *.o /S
cd ..
program.exe