import Control.Arrow
import Control.Monad
import Data.Bits
import Data.Char
import Data.Function
import qualified Data.List as L
import qualified Data.Map as M
import Data.Ord
import qualified Data.Set as S
import Debug.Trace (traceShow)
import Text.Printf

eps = 1.0e-12
maxIters = 100
big = 1.0e12
threshold = 1.0e10

type Source = (Double, Double)

parse :: [[String]] -> [(Double, Double, [Source])]
parse ([n', v', t'] : rest') = (v, t, sources) : parse rest
  where
    (n, v, t) = (read n', read v', read t')
    (sources', rest) = splitAt n rest'
    sources = map (\[dv', de'] -> (read dv', read de')) sources'
parse [] = []

volume :: Double -> [Source] -> Double
volume t = sum . map ((* t) . fst)

energy :: Double -> Double -> [Source] -> Double
energy _ _ [] = 0
energy t v ((dv, de):xs) = used * de + energy t (v - used) xs
  where
    used = min v (t * dv)

binSearch :: Int -> Double -> Double -> Double -> [Source] -> Double
binSearch 0 a _ _ _ = a
binSearch iters a b v sources = binSearch (iters - 1) a' b' v sources
  where
    (a', b') = if ok then (a, c) else (c, b)
    c = (a + b) / 2
    ok = volume c sources >= v && energy c v sources <= 0 && 0 <= energy c v (reverse sources)

work :: (Double, Double, [Source]) -> String
work (v, t, sources) = if minT < threshold then printf "%.8f" minT else "IMPOSSIBLE"
  where
    sources' = L.sortBy (compare `on` snd) $ map (second $ subtract t) sources
    minT = binSearch maxIters 0 big v sources'

main = interact $ unlines . zipWith (printf "Case #%d: %s") [1 :: Int ..] . map work . parse . map words . tail . lines
