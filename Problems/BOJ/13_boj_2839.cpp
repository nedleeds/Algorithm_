#include <iostream>
#include <unordered_map>
#include <vector>
#define INF 2134567890
using namespace std;

int s = 0;
int minCnt = INF;
vector<int> nums = { 3, 5 };
unordered_map<int, int> cntTable;

void dfs(int s, int total) {
	if (s >= total) {
		if (s == total) {
			int currCnt = 0;
			for (auto it : cntTable)
				currCnt += it.second;

			minCnt = min(minCnt, currCnt);
			int de = 1;
		}
		return;
	}

	for (auto n : nums) {
		if (n + s > total)
			continue;

		s += n;
		cntTable[n]++;

		dfs(s, total);

		s -= n;
		cntTable[n]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int n;
	cin >> n;

	dfs(s, n);

	if (minCnt == INF)
		minCnt = -1;

	cout << minCnt << '\n';

	return 0;
}