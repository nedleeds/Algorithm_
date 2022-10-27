#include <iostream>
#define INF 2134567890;
using namespace std;

int map[501][501];

// " Brute Force "
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int n, m, block;
	cin >> n >> m >> block;

	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
			cin >> map[r][c];

	// h: 0 ~ 256
	int minTime = INF;
	int minHeight = INF;
	for (int h = 0; h <= 256; h++) {
		int cntErase = 0;
		int cntStack = 0;

		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				if (map[r][c] > h)
					cntErase += map[r][c] - h;
				else if (map[r][c] < h)
					cntStack += h - map[r][c];
			}
		}

		if (cntErase + block >= cntStack) {
			int workTime = cntErase * 2 + cntStack;
			if (minTime >= workTime) {
				minTime = workTime;
				minHeight = h;
			}
		}
	}

	cout << minTime << ' ' << minHeight << '\n';

	return 0;
}