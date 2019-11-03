#include <cstdlib>
#include <iostream>

#include <functional>

using namespace std;

template<class A>
auto identity = [](A obj) { return obj; };

template<class A, class B, class C>
function<C(A)> compose(function<C(B)> f, function<B(A)> g) {
    return [f, g](A arg) { return f(g(arg)); };
}

auto inc = [](int x) { return x + 1; };

bool respectsIdentity() {
    function<int(int)> f = inc;
    function<int(int)> id = identity<int>;
    function<int(int)> f_id = compose(f, id);
    function<int(int)> id_f = compose(id, f);

    // return f_id == id_f; -- undefined operator==
    return false;
}

int main() {

    if(respectsIdentity()) cout << "respect!\n";
    else cout << "shame!\n";

    return 0;
}


