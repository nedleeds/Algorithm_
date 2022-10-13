#include <iostream>
#include <vector>
#include <cstring>
#define INF 2134567890
using namespace std;

int TESTCASE, N;
int MAX = -INF;
int MIN = INF;
int SIGNCNT[4]; // '+', '-', '*', '/'
vector<int> NUMS;
vector<int> IDX;

int compute() {
	// put first num
	int result = NUMS[0];

	for (int i = 0; i < IDX.size(); i++) {
		if (IDX[i] == 0)
			result += NUMS[i + 1];
		else if (IDX[i] == 1)
			result -= NUMS[i + 1];
		else if (IDX[i] == 2)
			result *= NUMS[i + 1];
		else if (IDX[i] == 3)
			result /= NUMS[i + 1];
	}
	return result;
}

void dfs(int lvl) {
	if (lvl == NUMS.size() - 1) {
		int v = compute();
		MAX = max(MAX, v);
		MIN = min(MIN, v);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (SIGNCNT[i]) {
			IDX.push_back(i);
			SIGNCNT[i]--;

			dfs(lvl + 1);

			IDX.pop_back();
			SIGNCNT[i]++;
		}
	}
}

void init() {
	MIN = INF;
	MAX = -INF;
	NUMS.clear();
	IDX.clear();
	memset(SIGNCNT, 0, 4);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> TESTCASE;

	for (int tc = 1; tc <= TESTCASE; tc++) {
		cin >> N;
		init();

		for (int i = 0; i < 4; i++)
			cin >> SIGNCNT[i];

		for (int i = 0; i < N; i++) {
			int value;
			cin >> value;
			NUMS.push_back(value);
		}
		dfs(0);

		cout << "#" << tc << ' ' << MAX - MIN << '\n';
	}

	return 0;
}

/*
10
5
2 1 0 1
3 5 3 7 9
6
4 1 0 0
1 2 3 4 5 6
5
1 1 1 1
9 9 9 9 9
6
1 4 0 0
1 2 3 4 5 6
4
0 2 1 0
1 9 8 6
6
2 1 1 1
7 4 4 1 9 3
7
1 4 1 0
2 1 6 7 6 5 8
8
1 1 3 2
9 2 5 3 4 9 5 6
10
1 1 5 2
8 5 6 8 9 2 6 4 3 2
12
2 1 6 2
2 3 7 9 4 5 1 9 2 5 6 4
*/