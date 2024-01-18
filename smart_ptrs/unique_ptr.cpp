#include <iostream>
#include <memory>
using namespace std;

int test(unique_ptr<int> a) { // reference of unique_ptr works, without reference doesn't
    cout << "a in test " << *a << endl;
    return *a;
}

int main() {
    unique_ptr<int> a = make_unique<int>(4); // unique_ptr<int> a(new int(4));

    cout << "a " << *a << endl;
    // unique_ptr<int> b = a; // cannot copy
    unique_ptr<int> c = move(a); // but can move, since it still means there is only 1 ptr
    cout << "c " << *c << endl;

    // test(c);
    test(move(c));
}
