#include <iostream>
#include <windows.h>
#include "vocabulary.h"

using namespace std;

int main() {
    Vocabulary V;
    V.read_file_to_cards("input.txt");
    for(auto X : V.copy_to_map())
    {
        cout << X.first << ' ' << X.second << '\n';
    }
    cout << "HHHHHHHHHHHH";
    V.sort_words();
    for(auto X : V.copy_to_map())
    {
        cout << X.first << ' ' << X.second << '\n';
    }
    cout << "HHHHHHHHHHHH";
    V.make_frequency_vocab();
    for(auto X : V.copy_to_map())
    {
        cout << X.first << ' ' << X.second << '\n';
    }
    cout << "HHHHHHHHHHHH";
    return 0;
}
