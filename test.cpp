#include <windows.h>


// Funtion declaration
int foo(void);


// Funtion definition
int foo(void)
{
    OutputDebugStringA("This is line break for windows.\r\n");
    OutputDebugStringA("This is line break for unix.\n");
    return 0;
}


int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
   
    char SmallS; // 8 bits - 256 different values [-128,127]
    char unsigned SmallU; // 8 bits - 256 different values [0,255]

    short MediumS; // 16 bits - 65536
    short unsigned MediumU;

    int LargeS; // 32 bits - 4 billion
    int unsigned LargeU;


    char unsigned Test;

    Test = 255;
    Test = Test + 1;


    return 0;
}