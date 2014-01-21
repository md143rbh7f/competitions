import Data.List

rec _ _ [] = 0
rec c k (x:xs) = c `div` k * x + rec (c+1) k xs
solve (k:xs) = rec k k (reverse (sort xs))
main = interact $ show . solve . tail . map read . words
