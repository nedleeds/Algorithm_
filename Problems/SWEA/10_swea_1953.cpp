#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int MAP[50][50];
int visit[50][50];
int testCase;
int N, M, R, C, L;
int ans;
int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0, -1, 1 };
struct Node {
	int r, c;
};

vector<int> dirs[7] = {
	// 0:╩С, 1:го, 2:аб, 3:©Л
	{0, 1, 2, 3},
	{0, 1},
	{2, 3},
	{0, 3},
	{1, 3},
	{1, 2},
	{0, 2}
};

void bfs(queue<Node> q) {
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		
		int idx = MAP[now.r][now.c] - 1;
		vector<int> dir = dirs[idx];
		for (int i = 0; i < dir.size(); i++) {
			Node next = { now.r + dR[dir[i]], now.c + dC[dir[i]] };
			if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= M)
				continue;
			if (MAP[next.r][next.c] == 0)
				continue;
			if (visit[next.r][next.c] != 0)
				continue;

			visit[next.r][next.c] = visit[now.r][now.c] + 1;
			q.push(next);
		}
	}
}

void cntProper() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (visit[r][c] > 0 && visit[r][c] <= L) {
				ans++;
				cout << "[" << r << "," << c << "]: " << ans<< '\n';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		cin >> N >> M >> R >> C >> L;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++)
				cin >> MAP[r][c];

		queue<Node> nodeQ;
		nodeQ.push({ R,C });
		visit[R][C] = 1;
		bfs(nodeQ);

		cout << '\n';
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cout << visit[r][c] << ' ';
			}
			cout << '\n';
		}

		cntProper();
		cout << "#" << tc <<" " << ans << '\n';
	}


	return 0;
}
/*
1
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0

1
10 10 4 3 9
0 0 0 0 0 0 0 0 0 0
0 0 0 7 5 0 5 0 0 0
0 0 3 2 2 6 0 0 0 0
0 4 7 2 2 2 7 0 0 4
0 3 0 1 1 2 2 0 0 5
0 5 6 1 1 1 1 6 2 5
7 4 1 2 0 0 4 6 0 0
5 3 1 7 0 2 2 6 5 7
7 3 2 1 1 7 1 0 2 7
3 4 0 0 4 0 5 1 0 1

*/