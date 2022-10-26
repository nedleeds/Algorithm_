#include <iostream>
#include <vector>
#define INF 2134567890
using namespace std;

int N;
int MAP[12][12];
int DAT[13];
int start = 0;
int minCost = INF;
vector<int> path;

void dfs(int from, int cost, int cnt) {
	if (from == start && cnt != 1) {
		minCost = min(minCost, cost);
		return;
	}

	for (int to = 0; to < N; to++) {
		if (DAT[to] != 0 && to != start)
			continue;
		if (to == start && cnt == 1)
			continue;
		if (to == start && cnt < N)
			continue;
		if (cost > minCost)
			continue;
		if (MAP[from][to] == 0)
			continue;

		DAT[to] = 1;
		cost += MAP[from][to];
		path.push_back(to);
		dfs(to, cost, cnt + 1);
		cost -= MAP[from][to];
		path.pop_back();
		DAT[to] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> N;

	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> MAP[r][c];

	start = 0;
	DAT[start] = 1;
	path.push_back(start);
	dfs(start, 0, 1);
	path.pop_back();
	DAT[start] = 0;

	cout << minCost << '\n';

	return 0;
}