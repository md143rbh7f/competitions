import qualified Data.Map as M
import Text.Printf

max_n = 12

base = [
	((1, 0, 0), "R"),
	((0, 1, 0), "P"),
	((0, 0, 1), "S")
	]

gen xs = [
	((r0 + r1, p0 + p1, s0 + s1), l0 ++ l1) |
	((r0, p0, s0), l0) <- xs,
	((r1, p1, s1), l1) <- xs,
	l0 < l1
	]

ans = map M.fromList $ take (max_n + 1) $ iterate gen base

work :: [Int] -> String
work [n, r, p, s] = M.findWithDefault "IMPOSSIBLE" (r, p, s) (ans !! n)

parse = map (map read . words) . tail . lines
unparse = unlines . zipWith (printf "Case #%d: %s") [1 :: Int ..]

main = interact $ unparse . map work . parse
