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
	// 1:��   2:��   3:��   4:��
	// 2:��   1:��   4:��   3:��
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
	// pq�� �̻��� ���� ����
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++) {
			VST[r][c] = false;
			if (MAP[r][c] != 0)
				PQ.push({ { r,c }, MAP[r][c], DIR[r][c] });
		}

	// �̻����� �ϳ��� next step ����
	while (!PQ.empty()) {
		Bug bug = PQ.top();
		PQ.pop();
		
		Pos now = bug.pos;
		int nowDir = bug.dir;

		Pos next = { now.r + dR[nowDir - 1], now.c + dC[nowDir - 1] };
		// �������� �Ѿ���� �ڸ�����
		if (!VST[now.r][now.c]) {
			MAP[now.r][now.c] = 0;
			DIR[now.r][now.c] = 0;
		}

		// �������� �Ѿ��
		// 1) �����ڸ� üũ
		if (isEdge(next)) {
			if (VST[next.r][next.c]) {
				// �̹� '�� ����' �̻��� �湮�� ��� -> ������
				// reason: Priority Queue ����
				MAP[next.r][next.c] += bug.cnt / 2;
			}
			else {
				// ù �湮 : cnt ���� + ���� ��ȯ + �湮 üũ
				MAP[next.r][next.c] = bug.cnt / 2;
				turn(bug.dir, next);
				VST[next.r][next.c] = true;
			}	
		}
		else {
			// 2) ���� ����
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

	freopen("../SampleInput/input.txt", "r", stdin);

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