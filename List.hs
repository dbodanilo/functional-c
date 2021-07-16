data List t = Empty | Cons t (List t)

-- concatenation
cat Empty lst = lst
cat (Cons x tail) lst = Cons x (cat tail lst)

  s e n d
+ m o r e
---------
m o n e y

-- d + e + 10*(n + r) + 100*(e + o) + 1000*(s + m)
-- = y + 10*e + 100*n + 1000*o + 10000*m

-- d + 101*e + 10*n + 10*r + 100*o + 1000*s + 1000*m
-- = y + 10*e + 100*n + 1000*o + 10000*m

-- 101*e - 10*e + 10*n - 100*n + 100*o - 1000*o + 11000*m
-- = y - d - 10*r - 1000*s

-- 91*e - 90*n - 900*o + 11000*m
-- = y - d - 10*r - 1000*s

int d, e, y, n, r, o, s, m,
    dpe, npr, epo, spm;
(int, int) dpec, nprc, epoc, spmc;

dpe[0] = y
(dpe[1] + npr[0])[0] = e 

(d + e)_0 = y
((d + e)_1 + (n + r)_0)_0 = e
(d + e)_ + ()
