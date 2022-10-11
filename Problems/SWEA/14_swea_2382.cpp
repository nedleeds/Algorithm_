#include <iostream>
#include <queue>
using namespace std;

int TESTCASE, K, N, M;
int MAP[100][100];
int DIR[100][100];
bool VST[100][100];

int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0, -1, 1 };

typedef struct _POS_ {
	int r, c;
}Pos;

typedef struct _BUG_ {
	Pos pos;
	int cnt, dir;
}Bug;

bool operator < (Bug a, Bug b) {
	if (a.cnt < b.cnt) return true;
	if (a.cnt < b.cnt) return false;
	return false;
}
priority_queue<Bug> PQ;

bool isEdge(Pos n) {
	return (n.r == 0 || n.r == N-1 || n.c == 0 || n.c == N-1);
}

void turn(int dir, Pos p) {
	// 1:상   2:하   3:좌   4:우
	// 2:하   1:상   4:우   3:좌
	if (dir == 1) {
		DIR[p.r][p.c] = 2;
	}
	else if (dir == 2) {
		DIR[p.r][p.c] = 1;
	}
	else if (dir == 3) {
		DIR[p.r][p.c] = 4;
	}
	else if (dir == 4) {
		DIR[p.r][p.c] = 3;
	}
}

void simulation() {
	// pq에 미생물 정보 저장
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++) {
			VST[r][c] = false;
			if (MAP[r][c] != 0)
				PQ.push({ { r,c }, MAP[r][c], DIR[r][c] });
		}

	// 미생물들 하나씩 next step 진행
	while (!PQ.empty()) {
		Bug bug = PQ.top();
		PQ.pop();
		
		Pos now = bug.pos;
		int nowDir = bug.dir;

		Pos next = { now.r + dR[nowDir - 1], now.c + dC[nowDir - 1] };
		// 다음으로 넘어가기전 자리비우기
		if (!VST[now.r][now.c]) {
			MAP[now.r][now.c] = 0;
			DIR[now.r][now.c] = 0;
		}

		// 다음으로 넘어가기
		// 1) 가장자리 체크
		if (isEdge(next)) {
			if (VST[next.r][next.c]) {
				// 이미 '더 많은' 미생물 방문한 경우 -> 덧셈만
				// reason: Priority Queue 적용
				MAP[next.r][next.c] += bug.cnt / 2;
			}
			else {
				// 첫 방문 : cnt 절반 + 방향 전환 + 방문 체크
				MAP[next.r][next.c] = bug.cnt / 2;
				turn(bug.dir, next);
				VST[next.r][next.c] = true;
			}	
		}
		else {
			// 2) 내부 진행
			if (VST[next.r][next.c])
				MAP[next.r][next.c] += bug.cnt;
			else {
				MAP[next.r][next.c] = bug.cnt;
				DIR[next.r][next.c] = bug.dir;
				VST[next.r][next.c] = true;
			}
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
		int ans = 0;

		cin >> N >> M >> K;

		// init MAP, DIR
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++) {
				MAP[r][c] = 0;
				DIR[r][c] = 0;
			}


		for (int i = 0; i < K; i++) {
			Bug bug;
			cin >> bug.pos.r >> bug.pos.c >> bug.cnt >> bug.dir;
			MAP[bug.pos.r][bug.pos.c] = bug.cnt;
			DIR[bug.pos.r][bug.pos.c] = bug.dir;
		}

		for (int i = 0; i < M; i++) {
			simulation();
		}

		
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				ans += MAP[r][c];
			}
		}


		cout << "#" << tc << " " << ans << "\n";
	}


	return 0;
}