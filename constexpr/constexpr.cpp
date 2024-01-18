#include <iostream>
#include <vector>

using namespace std;

constexpr int square(int x) {
    return x*x;
}

class test {
private:
    int x;
public:
    test() {}

    void printx() {
        cout << "x " << x << endl;
    }

    // NOT THE SAME AS void const changex() {
    void changex() const {
        // x = 1; // error: assignment of member ‘test::x’ in read-only object
        int y = 1;
    }
};

int main() 
{
    int a = 3;
    // constexpr int b = a; // fails

    const int c = 3;
    constexpr int d = square(c); // works

    const vector<int> v = {1, 2, 3};
    // v = {4}; // error: passing ‘const std::vector<int>’ as ‘this’ argument discards qualifiers 
    // v[0] = 4; // error: assignment of read only location

    int f = 4;
    int g = 6;
    const int* e = &f; // POINTER TO CONST INT
    // *e = 5; // error: assignment of read only location
    e = &g; // this is allowed since this is a pointer to const int

    cout << *e << endl;

    int* const h = &f; // CONST POINTER TO INT
    *h = 5; // this is allowed
    // h = &g; // error: assignment of read only location


    cout << *h << endl;

    test t;
    t.changex();
    t.printx();

    const test s;
    s.changex();
    // s.printx(); // error: passing ‘const test’ as ‘this’ argument discards qualifiers
}
