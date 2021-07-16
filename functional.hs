import Prelude hiding(sum)

main :: IO ()
main = print $ sumHalf [1, 2, 3]
-- main = print $ sum [1, 2, 3]

sumHalf :: [Double] -> Double
sumHalf = reduce addHalf 0

sum :: [Double] -> Double
sum = reduce add 0

-- f :: a -> b -> b
reduce :: (a -> b -> b) -> b -> [a] -> b
reduce f x [] = x
reduce f x (y : ys) = f y (reduce f x ys)

add :: Double -> Double -> Double
add x y = x + y

addHalf :: Double -> Double -> Double
addHalf i d = i/2 + d
