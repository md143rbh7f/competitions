import Data.List
main = interact $ show . length . filter (odd . length) . group
