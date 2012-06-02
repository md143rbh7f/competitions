import Data.Char
import Data.List

intToStr 0 = []
intToStr x = chr ( ( x - 1 ) `mod` 26 + ord 'A' ) : intToStr ( ( x - 1 ) `div` 26 )

strToInt = foldl ( \ x y -> 26 * x + ord y - ord 'A' + 1 ) 0

solve str =
	case parse str of
		[_,r,_,c] -> ( reverse . intToStr . read $ c ) ++ r
		[c,r] -> "R" ++ r ++ "C" ++ ( show . strToInt $ c )
	where parse = groupBy ( \ a b -> isDigit a == isDigit b )

main = interact $ unlines . map solve . tail . lines
