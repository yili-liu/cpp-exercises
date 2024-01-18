#include <iostream>
#include <string>
#include <memory>
using namespace std;
 
/*
int* count() {
    int myInt = 10;

    int* const p = &myInt;

    return p;
}
*/

unique_ptr<int> count() {
   unique_ptr<int> value(new int(5));
   return value;
}

/*
int * count() {
    int myInt = 5;

    int * p = new int;
    *p = myInt;

    return p;
}
*/

int main() {

    /*
    int* a = count();
    */

    unique_ptr<int> a = count();

    *a = 6;
    cout << *a << endl;

}
