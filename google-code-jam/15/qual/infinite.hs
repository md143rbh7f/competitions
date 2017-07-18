import Text.Printf

input = map (map read . words) . odds False . tail . lines

odds f (x:xs) = (if f then (x:) else id) (odds (not f) xs)
odds _ [] = []

output = unlines . zipWith (printf "Case #%d: %d") [1::Int ..] 

solve :: [Int] -> Int
solve xs = minimum $ map compute_cost [1 .. 1005]
	where compute_cost n = n + sum (map (\x -> (x - 1) `div` n) xs)

main = interact $ output . map solve . input
