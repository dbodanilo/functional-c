#include <iostream>
#include <functional>

#include "List.cpp"

// reverse
template<class T>
List<T> reverse(List<T> const & lst)
{
    return foldl([](List<T> const & acc, T v)
    {
        return List<T>(v, acc);
    }, List<T>(), lst);
}

// concatenation
template<class T>
List<T> concat(List<T> const & a, List<T> const & b)
{
    if(a.isEmpty())
        return b;
    return List<T>(a.front(), concat(a.pop_front(), b));
}

// for each (procedures with side effects)
template<class T, class F>
void forEach(List<T> lst, F f)
{
    static_assert(std::is_convertible<F, std::function<void(T)>>::value, 
                  "forEach requires a function type void(T)");
    if(!lst.isEmpty())
    {
        f(lst.front());
        forEach(lst.pop_front(), f);
    }
}
// example
template<class T>
void print(List<T> lst)
{
    forEach(lst, [](T v)
    {
        std::cout << "(" << v << ") ";
    });
    std::cout << std::endl;
}

// left fold (tail recursive)
// foldl :: (b -> a -> b) -> b -> [a] -> b
// foldl f acc [] = acc
// foldl f acc (x : xs) = foldl f (f acc x) xs
template<class T, class U, class F>
U foldl(F f, U acc, List<T> lst)
{
    static_assert(std::is_convertible<F, std::function<U(U, T)>>::value, 
                  "foldr requires a function type U(T, U)");
    if (lst.isEmpty())
        return acc;
    else 
        return foldl(f, f(acc, lst.front()), lst.pop_front());
}

// right fold (right/back to left/front)
// foldr :: (a -> b -> b) -> b -> [a] -> b
// foldr f acc [] = acc
// foldr f acc (x : xs) = f x (foldr f acc xs)
template<class T, class U, class F>
U foldr(F f, U acc, List<T> lst)
{
    static_assert(std::is_convertible<F, std::function<U(T, U)>>::value, 
                  "foldr requires a function type U(T, U)");
    if (lst.isEmpty())
        return acc;
    else
        return f(lst.front(), foldr(f, acc, lst.pop_front()));
}

// filter :: (a -> Boolean) -> [a] -> [a]
// filter p [] = []
// filter p (x : xs) = if p x
//                     then (x : (filter p xs))
//                     else (filter p xs)
template <class T, class P>
List<T> filter(P p, List<T> lst)
{
    static_assert(std::is_convertible<P, std::function<bool(T)>>::value,
                  "filter requires a function type bool(T)");
    if (lst.isEmpty())
        return List<T>();
    if (p(lst.front()))
        return List<T>(lst.front(), filter(p, lst.pop_front()));
    else
        return filter(p, lst.pop_front());
}

// fmap :: (a -> b) -> [a] -> [b]
// fmap f [] = []
// fmap f (x : xs) = (f x) : (fmap xs)
template <class U, class T, class F>
List<U> fmap(F f, List<T> lst)
{
    static_assert(std::is_convertible<F, std::function<U(T)>>::value,
                  "fmap requires a function type U(T)");
    if (lst.isEmpty())
        return List<U>();
    else
        return List<U>(f(lst.front()), fmap<U>(f, lst.pop_front()));
}

// example
// auto charLst2 = fmap<char>(toupper, charLst);
