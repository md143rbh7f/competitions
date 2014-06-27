import Data.List
import Data.Set as S

work cards = minimum [length s |
	s <- subsequences "RGBYW12345",
	size (S.map (intersect s) cards) == size cards
	]
main = interact $ show . work . fromList . tail . words
