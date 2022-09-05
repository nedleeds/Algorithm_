#include <iostream>
#include <vector>
using namespace std;
// G5
int n, ans = -2134567890;
string str;

int calculate(int a, int b, char op) {
	if (op == '+')
		a += b;
	else if (op == '-')
		a -= b;
	else if (op == '*')
		a *= b;

	return a;
}

void dfs(int idx, int cur) {
	if (idx >= n) {
		ans = max(ans, cur);
		return;
	}

	char op = idx == 0 ? '+' : str[idx - 1];

	if (idx + 2 < n) {
		int bracket = calculate(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		dfs(idx + 4, calculate(cur, bracket, op));
	}

	dfs(idx + 2, calculate(cur, str[idx] - '0', op));

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> str;

	dfs(0, 0);

	cout << ans;

	return 0;
}
/*

--->
*/