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
    foo();
    return 0;
}