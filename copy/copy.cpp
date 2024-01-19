#include <iostream>
using namespace std;

class complex {
    private:
        int r, i;
    public:
        complex() : r(0), i(0) {
            cout << "DEFAULT CTOR" << endl;
        };
        complex(int r, int i) : r(r), i(i) {
            cout << "CTOR" << endl;
        };
        ~complex() {
        }

        // copy constructor
        complex(complex& other) : r(other.r), i(other.i) {
            cout << "COPY CTOR" << endl;
        }

        // copy assignment operator
        complex& operator=(complex& other) {
            cout << "COPY ASSIGNMENT OP" << endl;
            // free any pointers
            r = other.r;
            i = other.i;
            return *this;
        }

        void print() {
            cout << "complex " << r << " " << i << endl;
        }
};

int main() {
    int a, b, c;
    c = 3;
    a = b = c;
    cout << "abc " << a << " " << b << " " << c << endl;

    a = b += c;
    cout << "abc " << a << " " << b << " " << c << endl;

    complex d(1, 3);
    d.print();

    complex e(d);
    e.print();

    complex f;
    f.print();
    f = e;
    f.print();

    complex g(2, 5);
    complex h, i;
    h.print();
    i.print();
    g.print();

    h = i = g;
    h.print();
    i.print();
    g.print();
}
