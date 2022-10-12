#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int TESTCASE, D, W, K, ANS;
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

bool isPass(int m[13][20]) {
	int passCnt = 0;
	// column wise check
	for (int c = 0; c < W; c++) {
		// row wise check
		for (int r = 0; r < D - 2; r++) {
			int r1 = m[r][c];
			int r2 = m[r + 1][c];
			int r3 = m[r + 2][c];
			if ((r1 == r2 && r2 == r3)){
				passCnt += 1;
				break;
			}
		}
	}
	if (passCnt == W)
		return true;
	else
		return false;
}

void inject(int idx, int m) {
	for (int i = 0; i < W; i++)
		TMP[idx][i] = m;
}

void restore(int idx) {
	for (int i = 0; i < W; i++)
		TMP[idx][i] = MAP[idx][i];
}

void dfs(int k, int cnt) {
	// evaluation
	if (isPass(TMP)) 
		ANS = cnt < ANS ? cnt : ANS;

	// finish condition
	if (k == D)
		return;

	// truncate - ANS should be minimum
	if (cnt >= ANS)
		return;

	for (int i = 0; i < 3; i++) {
		// 0:noChange, 1:A, 2:B
		if (i != 0) {
			inject(k, i - 1);
			dfs(k + 1, cnt + 1);
			restore(k);
		}
		else {
			dfs(k + 1, cnt);
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
		ANS = 0;

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