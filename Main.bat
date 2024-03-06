IF EXIST main.o DEL /F main.o
IF EXIST Main.exe DEL /F Main.exe
g++ -c main.cpp -I./Library/SFML-2.5.1/include -DSFML_STATIC
g++ -Wall main.o -o Main -L./Library/SFML-2.5.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main -lsfml-audio
IF EXIST Main.exe cls
IF EXIST Main.exe CALL Main.exe