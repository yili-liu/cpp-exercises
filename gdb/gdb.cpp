#include <iostream>
using namespace std;

/*
int* ret_pointer() {
    int result = 42;
    return &result;
}
*/

int main() {
    // pointer pitfalls


    /*
    // 1. nullptr dereferencing
    int* px = nullptr;
    *px = 42;
    */

    // 2. memory leaks
    // int* array = new int[1000];
    
    // 3. dangling pointers
    /*
    int* p = ret_pointer();
    cout << "p: " << *p << endl;
    */

    // 4. double free
    int* x = new int(4);
    delete x;
    delete x; // double free detected

    return 0;
}
