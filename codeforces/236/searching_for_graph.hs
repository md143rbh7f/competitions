work [n, p] = take (2 * n + p) [show i ++ " " ++ show ((mod (i + d) n) + 1) | d <- [0 ..], i <- [1 .. n]]
main = interact $ unlines . map (unlines . work . map read . words) . tail . lines
