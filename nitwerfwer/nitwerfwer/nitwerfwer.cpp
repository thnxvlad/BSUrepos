#include <iostream>

char* Strncpy(char* dest, const char* src, const size_t num_)
{
    //delete[] dest;
    int newLen_ = std::min(num_, strlen(src));
    /*for (int i = 0; i < newLen_; i++)
        *(dest++) = *(src++);
    *dest = '\0';*/
    char ndest[4] = { 'a', 'b', 'c' };
    dest = ndest;
    return dest;
}

int main() {
    char dest[3] = {'a', 'b'};
    const char * src = "nmuoghouvhghgv";
    Strncpy(dest, src, 20);
    for (int i = 0; i < strlen(dest); i++)
        std::cout << dest[i];
    return 0;
}