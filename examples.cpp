#include <iostream>

// map f lst = [f x | x <- lst]
// first impulse translation (does not compile)
// template<template<class> class f, class... lst> struct 
// map {
//     typedef f<lst>... type;
// };

// workaround: typelist entity
template<class...> struct
typelist;

template<class a, class... as> struct
typelist<a, as...> {
    typedef a head;
    typedef typelist<as...> tail;
};

template<template<class> class, class...> struct 
map;

template<template<class> class f, class hd, class... tl> struct 
map<f, hd, tl...> {
    typedef typelist<f<hd>, map<f, tl...>> type;
};

// sum [] = 0
// sum (head:tail) = head + (sum tail)

template<int...> struct
sum;

template<> struct 
sum<> {
    static const int value = 0;
};

template<int i, int... tail> struct
sum<i, tail...> {
    static const int value = i + sum<tail...>::value;
};

// foldr f init [] = init
// foldr f init (head:tail) =
//     f head (foldr f init tail)

template<template<class, int> class, int, class...> struct
fold_right;

template<template<class, int> class f, int init> struct
fold_right<f, init> {
    static const int value = init;
};

template<template<class, int> class f, int init, class head, class... tail> struct 
fold_right<f, init, head, tail...> {
    static const int value = f<head, fold_right<f, init, tail...>::value>::value;
};

// all pred [] = True
// all pred (head:tail) = (pred head) && (all pred tail)

template<template<class> class predicate, class... list> struct 
all;

template<template<class> class predicate> struct
all<predicate> {
    static const bool value = true;
};

template<template<class> class predicate, class head, class... tail> struct 
all<predicate, head, tail...> {
    static const bool value = 
        predicate<head>::value && 
        all<predicate, tail...>::value;
};

// or_combinator f1 f2 = 
//     \x -> (f1 x) || (f2 x)

template<template<class> class f1, template<class> class f2> struct 
and_combinator {
    template<class T> struct 
    lambda {
        static const bool value = f1<T>::value && f2<T>::value; 
    };
};

template<template<class> class f1, template<class> class f2> struct 
or_combinator {
    template<class T> struct
    lambda {
        static const bool value = f1<T>::value || f2<T>::value;
    };
};

// count the number of pointers in a list of types

// is_zero 0 = True
// is_zero x = False

template<class T> struct
isConst {
    static const bool value = false;
};

template<class U> struct
isConst<const U> {
    static const bool value = true;
};

template<class T> struct 
isPtr {
    static const bool value = false;
};

template<class U> struct
isPtr<U*> {
    static const bool value = true;
};

template<class U> struct
isPtr<U* const> {
    static const bool value = true;
};

template<class... lst> struct 
countPtrs {
    static const int value = sum<isPtr<lst>::value...>::value;
};

// count with list comprehension
// count lst = sum [1 | x <- lst]
// with auxiliary funciton one
// one x = 1
// count lst = sum [one x | x <- lst]

template<class T> struct
one {
    static const int value = 1;
};

template<class... lst> struct
count {
    static const int value = sum<one<lst>::value...>::value;
};

// count [] = 0
// count (head:tail) = 1 + count tail

template<class... list> struct
count;

template<> struct
count<> {
    static const int value = 0;
};

template<class head, class... tail> struct
count<head, tail...> {
    static const int value = 1 + count<tail...>::value;
};

// fact 0 = 1
// fact n = n * fact (n - 1)

template<int n> struct 
fact {
    static const int value = n * fact<n - 1>::value;
};

template<> struct 
fact<0> {
    static const int value = 1;
};

int main() {
    std::cout
        << "or_combinator isPtr isConst (const int) = "
        << or_combinator<isPtr, isConst>::lambda<const int>::value
        << std::endl;

    return 0;
}
