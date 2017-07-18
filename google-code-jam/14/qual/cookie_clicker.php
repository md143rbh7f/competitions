<?php
fscanf(STDIN, '%d', $cases);
for($num = 1; $num <= $cases; $num++) {
	fscanf(STDIN, '%f%f%f', $c, $f, $x);
	list($ans, $s, $t) = array(INF, 2, 0);
	for($i = 0; ; $i++) {
		$test = $t + $x / $s;
		if($test < $ans) {
			$ans = $test;
			$t += $c / $s;
			$s += $f;
		} else break;
	}
	printf("Case #%d: %0.7f\n", $num, $ans);
}
?>
