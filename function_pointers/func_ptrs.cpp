#include <iostream>
#include <functional>
using namespace std;

typedef int (*int_op)(int, int);

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    // function pointer for functions: int name(int, int)
    int (*op)(int, int);
    op = add;

    cout << op(3, 4) << endl;

    // typedef
    int_op another = multiply;
    cout << another(5, 6) << endl;

    function<int(int, int)> f = another;
    cout << f(3, 5) << endl;

    function<int(int)> fun = [&](int i) {
        if (i == 0) return 0;
        cout << "fun " << i << endl;
        return fun(i - 1);
    };

    fun(5);
}
