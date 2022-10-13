#include <iostream>
#include <algorithm>
#define INF 2134567890
using namespace std;

int TESTCASE, N, M;
int MAP[20][20];
int VST[20][20];
struct Ans { int revenue, houseCnt; } ANS;

void init(int m[20][20]) {
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			m[r][c] = 0;

	ANS = { -INF, -INF };
}

void getMax(int r1, int c1) {
	
	// diamond shape's diagonal length : [h * sqrt(2)]
	// -> [k < sqrt(2) * N] -> [k < 2 * N] 
	for (int k = 1; k < N * 2; k++) {
		int pay = (k * k) + (k - 1) * (k - 1);
		int paid = 0;

		// check total map 
		for (int r2 = 0; r2 < N; r2++)
			for (int c2 = 0; c2 < N; c2++) 
			{
				// check distance (with k)
				int dist = abs(r1 - r2) + abs(c1 - c2);
				if (dist <= k - 1) {
					if (MAP[r2][c2])
						paid += M;
				}
			}

		// not damaged( >= 0), max houses
		int revenue = paid - pay;
		if ((revenue >= 0) && (ANS.houseCnt < paid / M)) {
			ANS.houseCnt = paid / M;
			ANS.revenue = revenue;
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
		cin >> N >> M;
		init(MAP);

		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> MAP[r][c];

		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				getMax(r, c);

		cout << "#" << tc << " " << ANS.houseCnt << '\n';
	}

	return 0;
}