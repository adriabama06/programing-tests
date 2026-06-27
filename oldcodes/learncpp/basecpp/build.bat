cd src
g++ -c -std=c++17 *.cpp
g++ -o -std=c++17 ..\program.exe *.o
del *.o /S
cd ..
program.exe