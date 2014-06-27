import Data.List
work p (a, b) = if c > a then (c, b * (1 - p)) else (a, 0) where c = (1 - p) * a + p * b
main = interact $ show . fst . foldr work (0.0, 1.0) . sort . map read . tail . words
