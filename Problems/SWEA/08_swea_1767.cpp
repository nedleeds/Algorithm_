#include <iostream>
#include <vector>
using namespace std;

int MAP[12][12];
int testCase, N;
int minLineLen = 2134567890;
int maxCoreCnt = -2134567890;
int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0, -1, 1 };
struct CPU { int r, c; } core;
vector<CPU> cores;

bool isClear(CPU p, int direction) {
	if (direction == 0) {
		// up
		int row = p.r;
		for (int r = 0; r < row; r++)
			if (MAP[r][p.c] != 0)
				return false;
	}
	else if (direction == 1) {
		// down
		int row = p.r;
		for (int r = row + 1; r < N; r++)
			if (MAP[r][p.c] != 0)
				return false;
	}
	else if (direction == 2) {
		// left
		int col = p.c;
		for (int c = 0; c < col; c++)
			if (MAP[p.r][c] != 0)
				return false;
	}
	else if (direction == 3) {
		// right
		int col = p.c;
		for (int c = col + 1; c < N; c++)
			if (MAP[p.r][c] != 0)
				return false;
	}
	else {
		cout << "direction is wrong\n";
	}
	return true;
}

int checkLine(CPU p, int direction, int mode) {
	// mode: 0(=erase), 1(=draw)
	int row = p.r;
	int col = p.c;
	int step = 0;
	if (direction == 0) {
		for (int r = row; r >= 0; r--) {
			MAP[r][col] = (mode == 1) ? 2 : 0;
			step++;
		}
	}
	else if (direction == 1) {
		for (int r = row; r < N; r++) {
			MAP[r][col] = (mode == 1) ? 2 : 0;
			step++;
		}
	}
	else if (direction == 2) {
		for (int c = col; c >= 0; c--) {
			MAP[row][c] = (mode == 1) ? 2 : 0;
			step++;
		}
	}
	else if (direction == 3) {
		for (int c = col; c < N; c++) {
			MAP[row][c] = (mode == 1) ? 2 : 0;
			step++;
		}
	}

	return step;
}

void dfs(int idx, int coreCnt, int lineLen) {
	if (idx == cores.size()) {
		if (maxCoreCnt < coreCnt) {
			minLineLen = lineLen;
			maxCoreCnt = coreCnt;
		}
		else if (maxCoreCnt == coreCnt) {
			if (minLineLen > lineLen) minLineLen = lineLen;
		}
		return;
	}
	else {
		CPU now = cores[idx];

		// consider 5 cases: draw (4 directions) or Not
		for (int i = 0; i < 4; i++) {
			CPU next = { now.r + dR[i], now.c + dC[i] };
			if (MAP[next.r][next.c] != 0)
				continue;

			if (isClear(next, i)) {
				dfs(idx + 1, coreCnt + 1, lineLen + checkLine(next, i, 1));
				checkLine(next, i, 0);
			}
		}
		dfs(idx + 1, coreCnt, lineLen);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> testCase;
	for (int test = 1; test <= testCase; test++) {
		cin >> N;

		cores.clear();
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				cin >> MAP[row][col];

				// set the cores
				if (MAP[row][col] == 1) {
					if (row == 0 || row == N - 1 || col == 0 || col == N - 1)
						continue;
					cores.push_back({ row, col });
				}
			}
		}

		// dfs for all processor
		maxCoreCnt = -2134567890;
		minLineLen = 2134567890;
		dfs(0, 0, 0);

		cout << "#" << test << " " << minLineLen << '\n';

	}

	return 0;
}
/*
3
7
0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 0
1 1 0 1 0 0 0
0 1 0 0 0 0 0
0 0 0 0 0 0 0
9
0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1
11
0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1
0 0 0 1 0 0 0 0 1 0 0
0 1 0 1 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0

#1 12
#2 10
#3 24
*/