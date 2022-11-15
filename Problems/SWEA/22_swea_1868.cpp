#include <iostream>
#include <queue>
using namespace std;

int TestCase, N;
char Map[300][300];
bool Visit[300][300];
struct Pos { int r, c; };
int dR[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dC[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int nextFlag = true;

bool isVisitAll() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			if (Visit[r][c] != 1)
				return false;

	return true;
}

int bfs(Pos start) {
	if (Map[start.r][start.c] == '*') { return 0; }
	if (Visit[start.r][start.c] != 0) { return 0; }
	int click = 0;	 // click 수
	int cntBomb = 0; // 폭탄 수
	queue<Pos> q;	 // queue 세팅
	
	q.push(start);			 // 시작점 세팅
	while (!q.empty()) {
		click++;			 // 클릭수: 시작 = 1
		Pos now = q.front(); // 시작점 세팅
		q.pop();

		int cntBomb = 0;
		for (int i = 0; i < 8; i++) {
			Pos next = { now.r + dR[i], now.c + dC[i] }; // 다음점 세팅
			if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= N)  continue; // 범위
			if (Visit[next.r][next.c]) continue; // 이미 이전에 방문한 곳이면 통과

			Visit[next.r][next.c] = true; // 방문 체크
			if (Map[next.r][next.c] == '*') { cntBomb++; } // 현재의 8방향에서 * 발견
			else if (Map[next.r][next.c] == '.') { q.push(next); } // 갈 수 있는 곳 q에 추가
		}

		Map[now.r][now.c] = cntBomb;
		// 8방향 중에 폭탄이 존재 -> 종료
		if (cntBomb > 0) { break; }
	}

	return click;
}

void init() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(), cout.tie();

	freopen_s(new FILE*, "./SampleInput/input.txt", "r", stdin);

	cin >> TestCase;
	for (int tc = 1; tc <= TestCase; tc++) {
		cin >> N;

		// set Map
		for (int row = 0; row < N; row++)
			for (int col = 0; col < N; col++)
				cin >> Map[row][col];

		// for all the position
		int cntSum = 0;
		for (int row = 0; row < N; row++)
			for (int col = 0; col < N; col++) {
				if (Visit[row][col] != true) {
					Pos now = { row, col };

					cntSum += bfs(now);
					if (isVisitAll()) {
						cout << cntSum << '\n';
					}          

					init();
				}
			}
		int de = 1;
	}

	return 0;
}

/*
* ms lego car racing : foraza horizon 4

int cntBomb = 0;

- 현 위치에서
- for (8방향)
	- if 현 위치 == '*'
		-> cntBomb += 1
	- else if (현 위치 == '.')
		-> q.push(현 위치)

- 8방향 체크 후
- MAP[현위치] = cnt (지뢰수 표시)
- if (cnt != 0) 지뢰가 있으면
	-> q를 비워서 멈추도록
*/