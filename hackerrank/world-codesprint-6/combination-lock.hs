dist x y = if y < x then dist y x else min (y - x) (x + 10 - y)

work :: [[Int]] -> Int
work [xs, ys] = sum $ zipWith dist xs ys

parse = map (map read . words) . lines

main = interact $ show . work . parse
