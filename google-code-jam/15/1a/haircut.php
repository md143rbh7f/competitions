<?php

function simulate($vs, $t) {
	$work = function ($m) use ($t) {return 1 + (int) ($t / $m);};
	return array_sum(array_map($work, $vs));
}

function solve() {
	fscanf(STDIN, '%d%d', $b, $n);
	$ms = array_map('intval', explode(' ', fgets(STDIN)));

	$x = 0;
	$y = 100000000000001;
	while ($x < $y) {
		$z = (int) (($x + $y) / 2);
		if (simulate($ms, $z) < $n) {
			$x = $z + 1;
		} else {
			$y = $z;
		}
	}

	$n_ = $x ? simulate($ms, $x - 1) : 0;
	foreach ($ms as $i => $m) {
		if ($x % $m == 0) {
			$n_ += 1;
			if ($n_ == $n) {
				return $i + 1;
			}
		}
	}
	return -1;
}


fscanf(STDIN, '%d', $cases);
for($num = 1; $num <= $cases; $num++) {
	printf("Case #%d: %d\n", $num, solve());
}

?>
