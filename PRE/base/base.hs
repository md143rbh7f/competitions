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

mapBy :: (Ord k) => (a -> k) -> [a] -> M.Map k [a]
mapBy f = M.fromList . map (f . head &&& id) . L.groupBy ((==) `on` f) . L.sortBy (compare `on` f)

main = interact $
