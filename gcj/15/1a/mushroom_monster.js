var fs = require('fs');

function work(xs) {
	var n = xs.length - 1, m = 0, ans = [0, 0];
	for (var i = 0; i < n; i++) {
		var del = xs[i] - xs[i + 1];
		ans[0] += Math.max(del, 0);
		m = Math.max(del, m);
	}
	for (var i = 0; i < n; i++) {
		ans[1] += Math.min(m, xs[i]);
	}
	return ans;
}

fs.readFileSync('in', 'utf8').split('\n').forEach(
	function (line, index) {
		if (index && index % 2 == 0) {
			var xs = line.split(' ').map(function (word) {return parseInt(word);});
			var ans = work(xs);
			console.log('Case #' + index / 2 + ':', ans[0], ans[1]);
		}
	}
);
