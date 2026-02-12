#include <windows.h>

void bar(void)
{
    int BarVariable = 100;
    int* BarPointer = &BarVariable;


}

void foo(void)
{
    int FooVariable = 200;
    int* FooPointer = &FooVariable;


    bar();


}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    unsigned char Test;
    unsigned char* TestPointer = &Test;

    Test = 255;
    Test = Test + 1;

    foo();

    return 0;
}
