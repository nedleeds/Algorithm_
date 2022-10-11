#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int TESTCASE, D, W, K, ans;
int MAP[13][20];
int TMP[13][20];
struct Permute {
	vector<int> PATH;
	int cnt;
}PERMUTE1, PERMUTE2;

bool operator < (Permute a, Permute b) {
	if (a.cnt < b.cnt) return false;
	if (a.cnt > b.cnt) return true;
	return false;
}
typedef priority_queue<Permute> PQ;
PQ PQ1, PQ2;

void init(int m[13][20]) {
	for (int r = 0; r < D; r++)
		for (int c = 0; c < W; c++)
			m[r][c] = 0;
}

bool isPass(int m[13][20]) {
	int passCnt = 0;
	// column wise check
	for (int c = 0; c < W; c++) {
		// row wise check
		for (int r = 0; r < D - 2; r++) {
			int r1 = m[r][c];
			int r2 = m[r + 1][c];
			int r3 = m[r + 2][c];
			if ((r1 == r2 && r2 == r3)){
				passCnt += 1;
				break;
			}
		}
	}
	if (passCnt == W)
		return true;
	else
		return false;
}

void setPermute(int lvl, Permute P, PQ* pq) {
	if (lvl == 0) {
		pq->push(P);
		return;
	}

	for (int i = 0; i <= 1; i++) {
		P.PATH.push_back(i);
		if (i==1)
			P.cnt++;
		setPermute(lvl - 1, P, pq);
		P.PATH.pop_back();
		if (i == 1)
			P.cnt--;
	}
}

void change(Permute p) {
	for (int r = 0; r < D; r++)
		for (int c = 0; c < D; c++)
			TMP[r][c] = MAP[r][c];

	// 여기서 걸려버림... A로 바꿀지 B로 바꿀지
	// 순열을 한번더 ...?
	PERMUTE2 = { {0,}, 0 };
	while (!PQ2.empty()) { PQ2.pop(); };

	setPermute(p.cnt, PERMUTE2, &PQ2);
	
	for (int r = 0; r < D; r++) {
		if (p.PATH[r] == 1) {
			// A랑 B 둘 다 체크
		}
	}

}

void evaluate() {
	// 1st evaluation
	if (isPass(MAP)) return;

	// 2nd evaluation
	// permutation of D (0:no change, 1:change)
	// row change based on permutation
	setPermute(D, PERMUTE1, &PQ1);
	
	while (!PQ1.empty()) {
		Permute p = PQ1.top();
		PQ1.pop();

		int de = 1;
		init(TMP);
		change(p);
	}
	


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> TESTCASE;
	for (int tc = 1; tc <= TESTCASE; tc++) {
		cin >> D >> W >> K;
		ans = 0;

		// init MAP
		init(MAP);

		// set the MAP
		for (int r = 0; r < D; r++)
			for (int c = 0; c < W; c++)
				cin >> MAP[r][c];

		// start evaluate
		evaluate();

		cout << "#" << tc << " " << ans << "\n";
	}


	return 0;
}