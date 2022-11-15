#include <iostream>
#include <queue>
using namespace std;

int TestCase, N, M, K;
int Map[100][100];
int Tmp[100][100];
int Dir[100][100];
int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0, -1, 1 };
struct BUG { int r, c, cnt, dir; } Bug;

struct cmp {
	bool operator()(BUG a, BUG b) {
		if (a.cnt > b.cnt) return false;
		if (a.cnt < b.cnt) return true;
		return false;
	}
};
priority_queue<BUG, vector<BUG>, cmp> BugQ;
queue<BUG> TmpQ;

void move() {
	while (!BugQ.empty()) {
		BUG now = BugQ.top();
		BugQ.pop();

		// next position - 1시간 후
		int nr = now.r + dR[now.dir - 1];
		int nc = now.c + dC[now.dir - 1];

		// 범위 체크
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;

		// 세균 다음 위치 표시
		Tmp[nr][nc] += Map[now.r][now.c];
		Map[now.r][now.c] = 0;

		// 세균 다음 방향 표시
		int dir = Dir[nr][nc];
		if (Tmp[nr][nc] == 0) {
			dir = Dir[now.r][now.c];
		}

		// check edge
		if (nr == 0 || nr == N - 1 || nc == 0 || nc == N - 1) {
			// 가는 곳이 edge 인 경우 - 방향 반대로 설정
			if		(Dir[now.r][now.c] == 1) Dir[nr][nc] = 2;
			else if (Dir[now.r][now.c] == 2) Dir[nr][nc] = 1;
			else if (Dir[now.r][now.c] == 3) Dir[nr][nc] = 4;
			else if (Dir[now.r][now.c] == 4) Dir[nr][nc] = 3;

			// 미생물 절반
			Tmp[nr][nc] = Tmp[nr][nc] / 2;
		}

		if (Map[nr][nc])
			BugQ.push({ nr, nc, Map[nr][nc], Dir[nr][nc] });
	}

	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++) {
			Map[row][col] = Tmp[row][col];
			Tmp[row][col] = 0;
		}

	int de1 = 1;
}

void reset() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++) {
			Map[r][c] = 0;
			Dir[r][c] = 0;
		}

	while (!BugQ.empty()) { BugQ.pop(); }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(), cout.tie();

	freopen_s(new FILE*, "./SampleInput/input.txt", "r", stdin);

	cin >> TestCase;
	for (int tc = 1; tc <= TestCase; tc++) {
		cin >> N >> M >> K;

		for (int i = 0; i < K; i++) {
			cin >> Bug.r >> Bug.c >> Bug.cnt >> Bug.dir;
			Map[Bug.r][Bug.c] = Bug.cnt;
			Dir[Bug.r][Bug.c] = Bug.dir;
			BugQ.push(Bug);
		}

		for (int t = 0; t < M; t++) {
			move();
		}

		int s = 0;
		for (int r = 1; r < N - 1; r++)
			for (int c = 1; c < N - 1; c++)
				s += Map[r][c];

		cout << "#" << tc << " " << s << '\n';

		reset();
	}

	return 0;
}

/*
[문제]
- 정사각형 구역 안에 K 개의 미생물 군집
- 가로 N개, 세로 N개 정사각형
- 미생물들이 구역을 벗어나는걸 방지하기 위해, 가장 바깥쪽 가장자리 부분에 위치한 셀들에는 특수한 약품이 칠해져 있다

1. 최초 각 미생물 군집의 위치와 군집 내 미생물의 수, 이동 방향이 주어진다
   약품이 칠해진 부분에는 미생물이 배치되어 있지 않다
   이동 방향은 상, 하, 좌, 우 네 방향 중 하나이다

2. 각 군집들은 1시간마다 이동방향에 있는 다음 셀로 이동

3. 미생물 군집이 이동 후 약품이 칠해진 셀에 도착하면 군집 내 미생물의 절반이 죽고, 이동방향이 반대로 바뀐다
   미생물 수가 홀수인 경우 반으로 나누어 떨어지지 않으므로, 다음과 같이 정의한다
   살아남은 미생물 수 = 원래 미생물 수를 2로 나눈 후 소수점 이하를 버림 한 값
   따라서 군집에 미생물이 한 마리 있는 경우 살아남은 미생물 수가 0이 되기 때문에, 군집이 사라지게 된다

4. 이동 후 두 개 이상의 군집이 한 셀에 모이는 경우 '군집들이 합쳐지게 된다'
   합쳐 진 군집의 미생물 수는 군집들의 미생물 수의 합이며, 이동 방향은 군집들 중 미생물 수가 가장 많은 군집의 이동방향이 된다
   합쳐지는 군집의 미생물 수가 같은 경우는 주어지지 않으므로 고려하지 않아도 된다

- M 시간 동안 이 미생물 군집들을 격리하였다
  M시간 후 남아 있는 미생물 수의 총합을 구하여라

[제약사항]
1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 5초
2. 5 ≤ N ≤ 100
3. 5 ≤ K ≤ 1,000
4. 1 ≤ M ≤ 1,000
5. 최초 약품이 칠해진 가장자리 부분 셀에는 미생물 군집이 배치되어 있지 않다
6. 최초에 둘 이상의 군집이 동일한 셀에 배치되는 경우는 없다
7. 각 군집 내 미생물 수는 1 이상 10,000 이하의 정수이다
8. 군집의 이동방향은 상하좌우 4방향 중 한 방향을 가진다. (상: 1, 하: 2, 좌: 3, 우: 4)
9. 주어진 입력으로 진행하였을 때, 동일한 셀에 같은 미생물 수를 갖는 두 군집이 모이는 경우는 발생하지 않는다
10. 각 군집의 정보는 세로 위치, 가로 위치, 미생물 수, 이동 방향 순으로 주어진다. 각 위치는 0번부터 시작한다

[입력]

- 첫 줄에는 총 테스트 케이스의 개수 T가 주어진다
- 그 다음 줄부터 T개의 테스트 케이스가 차례대로 주어진다
- 각 테스트 케이스의 첫째 줄에는 구역의 한 변에 있는 셀의 개수 N, 격리 시간 M, 미생물 군집의 개수 K가 순서대로 주어진다
- 다음 K줄에 걸쳐서 미생물 군집 K개의 정보가 주어진다
- 미생물 군집의 정보는 '세로 위치', '가로 위치', '미생물 수', '이동 방향' 순으로 4개의 정수가 주어진다
*/