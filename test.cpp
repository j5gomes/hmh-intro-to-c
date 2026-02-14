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

struct projectile
{
    // NOTE(gomes): this are the members, or the "fields", of this structure!

    char unsigned IsThisOnFire; // NOTE(gomes): 1 If it's on fire, 0 if it's not
    int Damage; // NOTE(gomes): This is how much damage it does on impact
    int ParticlesPerSecond; // NOTE(gomes): For special effects
    short HowManyCooks; // NOTE(gomes): Too many cooks?

    // 1 byte + 4 bytes + 4 bytes + 2 bytes = 11 bytes (actually 16)
};

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    projectile Test;


    int SizeOfChar = sizeof(char unsigned);
    int SizeOfShort = sizeof(short);
    int SizeOfInt = sizeof(int);
    int SizeOfProjectile = sizeof(projectile);
    int Size = sizeof(Test);

    Test.IsThisOnFire = 1;
    Test.Damage = 2;
    Test.ParticlesPerSecond = 3;
    Test.HowManyCooks = 4;

    // short *MrPointerMan = &Test; We cant do this because C is static typed
    unsigned short* MrPointerMan = (unsigned short *)&Test; // but we can cast it

    return 0;
}