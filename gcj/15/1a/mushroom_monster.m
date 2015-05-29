for i = 1 : scanf('%d', 1)
	n = scanf('%d', 1);
	nums = scanf('%d', n);
	delta = max(0, nums(1 : end - 1) - nums(2 : end));
	printf('Case #%d: %d %d\n', i, sum(delta), sum(min(max(delta), nums(1 : end - 1))));
end
