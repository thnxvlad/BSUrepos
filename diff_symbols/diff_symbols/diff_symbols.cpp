#include <iostream>

using namespace std;

int main()
{
    //посчитать кол-во различных символов через ассемблерную вставку
    char a[] = "abhsdfjsss";
    int b[256];
    for (int i = 0; i < 256; i++) b[i] = 0;
    int a_size = size(a);
    a_size--;
    __asm {
        mov ecx, a_size;
    cycle1:
        mov al, a[ecx - 1]
        cbw
        cwde
        mov edi, eax
        inc b[edi * 4]
        loop cycle1
    }
    for (int i = 0; i < 256; i++)
        if (b[i] != 0) cout << char(i) << " : " << b[i] << '\n';
}
