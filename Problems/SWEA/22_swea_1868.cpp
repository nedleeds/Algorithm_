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
	int click = 0;	 // click ��
	int cntBomb = 0; // ��ź ��
	queue<Pos> q;	 // queue ����
	
	q.push(start);			 // ������ ����
	while (!q.empty()) {
		click++;			 // Ŭ����: ���� = 1
		Pos now = q.front(); // ������ ����
		q.pop();

		int cntBomb = 0;
		for (int i = 0; i < 8; i++) {
			Pos next = { now.r + dR[i], now.c + dC[i] }; // ������ ����
			if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= N)  continue; // ����
			if (Visit[next.r][next.c]) continue; // �̹� ������ �湮�� ���̸� ���

			Visit[next.r][next.c] = true; // �湮 üũ
			if (Map[next.r][next.c] == '*') { cntBomb++; } // ������ 8���⿡�� * �߰�
			else if (Map[next.r][next.c] == '.') { q.push(next); } // �� �� �ִ� �� q�� �߰�
		}

		Map[now.r][now.c] = cntBomb;
		// 8���� �߿� ��ź�� ���� -> ����
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

- �� ��ġ����
- for (8����)
	- if �� ��ġ == '*'
		-> cntBomb += 1
	- else if (�� ��ġ == '.')
		-> q.push(�� ��ġ)

- 8���� üũ ��
- MAP[����ġ] = cnt (���ڼ� ǥ��)
- if (cnt != 0) ���ڰ� ������
	-> q�� ����� ���ߵ���
*/