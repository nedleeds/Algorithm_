#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int x, y, c, r;
	cin >> x >> y >> c >> r;

	int ans = min(min(x, c-x), min(y, r-y));
	cout << ans;

	return 0;
}