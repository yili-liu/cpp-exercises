#include <iostream>
using namespace std;

void f(int& a) {
    cout << "lvalue ref" << endl;
}

void f(const int& a) {
    cout << "const lvalue ref" << endl;
}

void f(int&& a) {
    cout << "rvalue ref" << endl;
}

void lv(int& a) {
    cout << "lv lvalue ref" << endl;
}

void rv(int&& a) {
    a = 7;
    cout << "rv rvalue ref" << endl;
}


int main() {
    int a = 3;
    const int b = 3;
    int& c = a;
    int&& d = 5;

    f(a);
    f(b);
    f(c);
    f(d);
    f(1);
    f(move(a));
    rv(move(d));
    // rv(a); // cannot bind rvalue to lvalue
    cout << "d after move is " << d << endl;
    // lv(3); // cannot bind lvalue to rvalue

}
