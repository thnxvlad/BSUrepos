#include <iostream>
using namespace std;

class A {
public:
    void method1() { cout << "method 1" << endl; }
};

class B : public A {
public:
    void method2() { cout << "method 2" << endl; }
};

int main() {
    A a;
    a.method2();
    return 0;
}