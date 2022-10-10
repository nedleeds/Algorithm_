#include <iostream>
using namespace std;

int testCase, K;
int map[5][9];

void rotate(int chain, int dir) {
	if (dir == 1) {
		int last = map[chain][8];
		for (int c = 7; c >= 1; c--) {
			map[chain][c + 1] = map[chain][c];
		}
		map[chain][1] = last;
	}
	else {
		int first = map[chain][1];
		for (int c = 2; c <= 8; c++) {
			map[chain][c - 1] = map[chain][c];
		}
		map[chain][8] = first;
	}
}

void doRotate(int chain, int dir) {
	int leftFaced = map[chain][7];
	int rightFaced = map[chain][3];

	rotate(chain, dir);

	// left side check
	int d = dir;
	for (int i = chain - 1; i >= 1; i--) {
		if (leftFaced != map[i][3]) {
			d *= -1;
			leftFaced = map[i][7];
			rotate(i, d);
		}
		else
			break;
	}

	// right side check
	d = dir;
	for (int i = chain + 1; i <= 4; i++) {
		if (rightFaced != map[i][7]) {
			d *= -1;
			rightFaced = map[i][3];
			rotate(i, d);
		}
		else
			break;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen("sample_input.txt", "r", stdin);

	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		cin >> K;

		for (int r = 1; r <= 4; r++)
			for (int c = 1; c <= 8; c++)
				cin >> map[r][c];

		for (int i = 0; i < K; i++) {
			int chain, dir;
			cin >> chain >> dir;
			doRotate(chain, dir);
		}

		int ans = 0;
		for (int chain = 1; chain <= 4; chain++)
			if (map[chain][1] == 1) {
				ans += 1 << (chain - 1);
			}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
/*
1
2
1 0 0 1 0 0 0 0 -> 0|1 0 0 1 0 0 0 0
0 1 1 1 1 1 1 1 -> 0|0 1 1 1 1 1 1 1
0 1 0 1 0 0 1 0 -> 0|0 0 1 0 1 0 0 1
0 1 0 0 1 1 0 1 -> 0|1 0 0 1 1 0 1 0
3 1
1 1
*/