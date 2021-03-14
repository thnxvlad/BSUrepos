#include <iostream>

int main()
{
	// (x^2 + y^2 + z^2) / 2   /// x,y - 2 bytes; z - 4 bytes
	short int x = 7, y = 2;
	int z = 3;
	_asm {
		mov ax, x
		mul ax
		mov x, ax
		mov ax, y
		mul ax
		add x, ax
		mov eax, z
		mul eax
		mov z, eax
		mov ax, x
		cwde
		add eax, z
		mov ebx, 2
		div ebx
		mov z, eax
	}
	std::cout << z;
}
