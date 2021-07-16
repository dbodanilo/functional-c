// all pred [] = True
// all pred (head:tail) = pred head && all pred tail

// slightly more verbose version
// all pred list =
//     if null list 
//     then True
//     else pred (head list) && all pred (tail list)

// using decomposition
// all pred [] = True
// all pred (head:tail) = pred head && tailResult
//     where tailResult = all pred tail

// in D
/***

*/
template allSatisfy(alias F, T...) {
    static if (T.length == 1)
    {
        alias allSatisfy = F!(T[0]);
    }
    else
    {
        enum bool allSatisfy = F!(T[0]) && allSatisfy!(F, T[1 .. $]);
    }
}

// parametrized runtime function
/***

*/
bool all(alias pred, Range)(Range r) {
    foreach(e; r) 
        if(!pred(e))
            return false;

    return true;
}
