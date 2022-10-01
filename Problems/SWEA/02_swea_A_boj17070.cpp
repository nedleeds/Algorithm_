#include <iostream>
using namespace std;
// G5
string str;
int MAP[18][18];
int visited[18][18];
int n, ans;

struct Pos { int r, c; } start = { 1, 2 };

int dir[3][2] = {
	{0, 1},
	{1, 0},
	{1, 1}
};

void dfs(Pos now, int mode) {
	if (now.r == n && now.c == n) {
		ans++;
		return;
	}

	// 0:가로, 1:세로, 2:대각선
	for (int nextMode = 0; nextMode < 3; nextMode++) {
		if (mode == 0 && nextMode == 1) // 현재 가로모드, 다음 세로모드
			continue;
		if (mode == 1 && nextMode == 0) // 현재 세로모드, 다음 가로모드
			continue;
		Pos next = { now.r + dir[nextMode][0], now.c + dir[nextMode][1] };
		int nr = next.r;
		int nc = next.c;
		if (nr <= 0 || nc <= 0 || nr > n || nc > n)
			continue;
		if (visited[nr][nc] != 0)
			continue;
		if (MAP[nr][nc] == 1)
			continue;
		if (nextMode == 2) {  // 다음 대각모드 - 벽 체크
			if (MAP[nr - 1][nc] || MAP[nr][nc - 1])
				continue;
		}

		visited[nr][nc] = 1;
		dfs(next, nextMode);
		visited[nr][nc] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;

	for (int r = 1; r <= n; r++)
		for (int c = 1; c <= n; c++)
			cin >> MAP[r][c];

	visited[1][2] = 1;
	dfs({ 1, 2 }, 0);

	cout << ans;

	return 0;
}