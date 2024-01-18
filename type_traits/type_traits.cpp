#include <iostream>
#include <type_traits>

using namespace std;

class Class {};

// possible implementation of std::move
// first remove reference of arg and then cast it to a &&
/*
template <typename T>
typename remove_reference<T>::type&& move(T&& arg) {
    return static_cast<typename remove_reference<T>::type&&>(arg);
}
*/

// C++14 has a simplified syntax for reading value and type
template <typename T>
void simplified_syntax() {
    // std::is_signed<T>::value;     /* ---> */   std::is_signed_v<T>;
    // std::remove_const<T>::type;   /* ---> */   std::remove_const_t<T>;
}

template <typename T>
void paramT(T arg) {
    cout << "paramT: " << arg << "\n";
    arg = 0;
}

template <typename T>
void paramTRef(T& arg) {
    cout << "paramTRef: " << arg << "\n";
    arg = 1;
}

template <typename T>
void paramTRvalue(T&& arg) {
    cout << "paramTRvalue: " << arg << "\n";
    arg = 2;
}

int main() 
{
    // the type trait is_floating_point evaluates if a type is a floating point
    std::cout << std::is_floating_point<Class>::value << '\n'; // 0
    std::cout << std::is_floating_point<float>::value << '\n'; // 1
    std::cout << std::is_floating_point<int>::value << '\n'; // 0

    // test params
    int a = 5;
    paramT(a); // prints 5
    paramT(5); // prints 5
    paramTRef(a); // prints 5; updates a to 1
    paramTRef(5); // error
    paramTRvalue(a); // prints 1; updates a to 2
    paramTRvalue(5); // passes
    paramTRvalue(a); // prints 1; updates a to 2


    /*
    The compiler, as with any regular template stuff, will generate three 
    different structs for you under the hood:

    struct is_floating_point_Class {
        static const bool value = false;
    };

    struct is_floating_point_float {
        static const bool value = true;
    };

    struct is_floating_point_int {
        static const bool value = false;
    };

    Since this is template metaprogramming, everything takes place at compile 
    time.
    */


}
