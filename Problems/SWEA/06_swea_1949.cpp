#include <iostream>
#include <queue>
using namespace std;

int testCase, mapSize, K, maxH;
int maxStep = -2134567890;
int MAP[8][8];
int visited[8][8];
int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0,-1, 1 };
struct Node { int r, c; };
queue<Node> highestNodes;

void initMAP(int M[8][8]) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			M[i][j] = 0;
}

void dfs(Node now, int nowHeight, int step, int isDig) {
	maxStep = max(step, maxStep);
	for (int idx = 0; idx < 4; idx++) {
		Node next = { now.r + dR[idx], now.c + dC[idx] };
		int nextHeight = MAP[next.r][next.c];
		int digFlag = 0;
		if (next.r < 0 || next.c < 0 || next.r >= mapSize || next.c >= mapSize)
			continue;
		if (visited[next.r][next.c])
			continue;
		if (nextHeight - K >= nowHeight)
			continue;
		if (nextHeight >= nowHeight && isDig)
			continue;
		if (nextHeight >= nowHeight) {
			nextHeight = nowHeight - 1;
			isDig = 1;
			digFlag = 1;
		}
		visited[next.r][next.c] = nextHeight;
		dfs(next, nextHeight, step + 1, isDig);
		visited[next.r][next.c] = 0;
		if (digFlag) { isDig = 0; }
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int ans = 0;
	cin >> testCase;

	for (int tc = 1; tc <= testCase; tc++) {
		cin >> mapSize >> K;
		initMAP(MAP);
		maxH = -2134567890;
		for (int row = 0; row < mapSize; row++) {
			for (int col = 0; col < mapSize; col++) {
				cin >> MAP[row][col];

				// highest point search + set maxHeightNodes
				if (MAP[row][col] > maxH) {
					// max height has been updated -> make Q empty
					maxH = MAP[row][col];
					while (!highestNodes.empty()) {
						highestNodes.pop();
					}
					highestNodes.push({ row, col });
				}
				else if (MAP[row][col] == maxH) {
					// found max height -> put node to Q
					highestNodes.push({ row, col });
				}
			}
		}
		// the maxH and the highestNodes have been renewed
		// find longest road based on highestNodes
		int longest = -2134567890;
		maxStep = -2134567890;
		while (!highestNodes.empty()) {
			Node start = highestNodes.front();
			int startHeight = MAP[start.r][start.c];
			highestNodes.pop();

			initMAP(visited);
			visited[start.r][start.c] = startHeight;
			dfs(start, startHeight, 1, 0);
			longest = max(longest, maxStep);
		}
		cout << "#" << tc << " " <<	 longest << '\n';
	}
	return 0;
}

/*
1
5 1
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8

1
8 2
5 20 15 11 1 17 10 14
1 1 11 16 1 14 7 5
17 2 3 4 5 13 19 20
6 18 5 16 6 7 8 5
10 4 5 4 9 2 10 16
2 7 16 5 8 9 10 11
12 19 18 8 7 11 15 12
1 20 18 17 16 15 14 13

ans) 6, 3, 7, 4, 2, 12


10
5 1
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
3 2
1 2 1
2 1 2
1 2 1
5 2
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
4 4
8 3 9 5
4 6 8 5
8 1 5 1
4 9 5 5
4 1
6 6 1 7
3 6 6 1
2 4 2 4
7 1 3 4
5 5
18 18 1 8 18
17 7 2 7 2
17 8 7 4 3
17 9 6 5 16
18 10 17 13 18
6 4
12 3 12 10 2 2
13 7 13 3 11 6
2 2 6 5 13 9
1 12 5 4 10 5
11 10 12 8 2 6
13 13 7 4 11 7
7 3
16 10 14 14 15 14 14
15 7 12 2 6 4 9
10 4 11 4 6 1 1
16 4 1 1 13 9 14
3 12 16 14 8 13 9
3 4 17 15 12 15 1
6 6 13 6 6 17 12
8 5
2 3 4 5 4 3 2 1
3 4 5 6 5 4 3 2
4 5 6 7 6 5 4 3
5 6 7 8 7 6 5 4
6 7 8 9 8 7 6 5
5 6 7 8 7 6 5 4
4 5 6 7 6 5 4 3
3 4 5 6 5 4 3 2
8 2
5 20 15 11 1 17 10 14
1 1 11 16 1 14 7 5
17 2 3 4 5 13 19 20
6 18 5 16 6 7 8 5
10 4 5 4 9 2 10 16
2 7 16 5 8 9 10 11
12 19 18 8 7 11 15 12
1 20 18 17 16 15 14 13

*/
