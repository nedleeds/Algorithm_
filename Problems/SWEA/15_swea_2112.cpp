#include <iostream>
#include <algorithm>
#include <queue>
#define INF 2134567890
using namespace std;

int TESTCASE, D, W, K;
int ANS = INF;
int MAP[13][20];
int TMP[13][20];
struct Permute {
	vector<int> PATH;
	int cnt;
}PERMUTE1, PERMUTE2;

bool operator < (Permute a, Permute b) {
	if (a.cnt < b.cnt) return false;
	if (a.cnt > b.cnt) return true;
	return false;
}

typedef priority_queue<Permute> PQ;
PQ PQ1, PQ2;

void init(int m[13][20]) {
	for (int r = 0; r < D; r++)
		for (int c = 0; c < W; c++)
			m[r][c] = 0;
}

bool isOkay() {
	int passCnt = 0;
	// column wise check
	for (int c = 0; c < W; c++) {
		// row wise check
		int cnt = 1;
		for (int r = 0; r < D - (K - 1); r++) {
			int first = TMP[r][c];
			for (int dR = 1; dR < K; dR++) {
				if (first != TMP[r + dR][c]) {
					cnt = 1;
					break;
				}
				else
					cnt++;
			}
			if (cnt == K)
				break;
		}
		if (cnt < K)
			return false;
	}
	return true;
}

void inject(int r, int m) {
	for (int c = 0; c < W; c++)
		TMP[r][c] = m;
}

void restore(int r) {
	for (int c = 0; c < W; c++)
		TMP[r][c] = MAP[r][c];
}

void dfs(int row, int cnt) {
	// check whole MAP
	if (isOkay()){
		ANS = min(ANS, cnt);
		return;
	}

	// finished
	if (row == D) {
		return;
	}

	// truncate - ANS should be minimum
	if (cnt > ANS)
		return;

	// choose whether inject or not by DFS
	for (int i = 0; i < 3; i++) {
		if (i != 0) {
			// change - 1(A:0), 2(B:1)
			inject(row, i - 1);
			dfs(row + 1, cnt + 1);
			restore(row);
		}
		else {
			// noChange
			dfs(row + 1, cnt);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> TESTCASE;
	for (int tc = 1; tc <= TESTCASE; tc++) {
		cin >> D >> W >> K;
		ANS = INF;

		// init MAP
		init(MAP);
		// set the MAP
		for (int r = 0; r < D; r++)
			for (int c = 0; c < W; c++) {
				cin >> MAP[r][c];
				TMP[r][c] = MAP[r][c];
			}
		// start evaluate
		dfs(0, 0);

		cout << "#" << tc << " " << ANS << "\n";
	}

	return 0;
}