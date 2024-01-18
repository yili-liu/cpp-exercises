#include <iostream>
using namespace std;

void foo() {
}

int square(int a) {
    for (int i = 0; i < 3; i++) {
        a++;
    }
    return a;
}

int main() {
    int x = 42;
    float y = 72;
    char a = 'a';
    signed char b = 'b';
    unsigned char c = 'c';
    char f = 'f';
    int z = 2;
    char d = 'd';
    char* e = "test";

    cout << "x: " << &x << endl;
    cout << "y: " << &y << endl;
    cout << "a: " << &a << endl;
    cout << "b: " << &b << endl;
    cout << "c: " << &c << endl;
    cout << "f: " << &f << endl;
    cout << "d: " << &d << endl;
    cout << "e: " << e << endl;

    cout << "a: " << (void*)(&a) << endl;
    cout << "b: " << (void*)(&b) << endl;
    cout << "c: " << (void*)(&c) << endl;
    cout << "f: " << (void*)(&f) << endl;
    cout << "z: " << (void*)(&z) << endl;
    cout << "d: " << (void*)(&d) << endl;
    cout << "foo: " << (void*)(&foo) << endl;
    cout << "square: " << (void*)(&square) << endl;
    cout << "main: " << (void*)(&main) << endl;
    cout << "foo to square: " << ((long)&square - (long)&foo) << endl;
    cout << "square to main: " << ((long)&main - (long)&square) << endl;
}
