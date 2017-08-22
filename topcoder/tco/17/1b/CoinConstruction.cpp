#include <vector>

using namespace std;

typedef vector<int> vi;

struct CoinConstruction {
vi construct(int k) {
	vi ans;
	int p = 1;
	while (2 * p - 1 <= k) {
		ans.push_back(p);
		p *= 2;
	}
	if (k > p - 1) {
		ans.push_back(k - p + 1);
	}
	return ans;
}
};
