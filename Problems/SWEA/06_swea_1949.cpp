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