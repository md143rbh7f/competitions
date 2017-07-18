import Data.List
import Text.Printf

can ([row] : vals) = vals !! (row - 1)

check [] = "Volunteer cheated!"
check [x] = show x
check _ = "Bad magician!"

solve [] = []
solve xs = check (intersect (can x) (can y)) : solve zs where
	(x, ys) = splitAt 5 xs
	(y, zs) = splitAt 5 ys

output = unlines . zipWith (printf "Case #%d: %s") ([1 :: Int .. ])
input = map (map read . words) . tail . lines

main = interact $ output . solve . input
