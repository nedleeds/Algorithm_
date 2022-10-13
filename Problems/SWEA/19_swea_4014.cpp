#include <iostream>
#include <vector>
using namespace std;

int TESTCASE, N, X;
int MAP[20][20];

void init() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			MAP[r][c] = 0;
}

bool isOut(int idx){
	return idx < 0 || idx >= N;
}


bool check(vector<int> v) {
	int leftSlope[20] = { 0, };
	int rightSlope[20] = { 0, };

	// height's diff > 2 : return false;
	for (int i = 0; i < N - 1; i++)
		if (abs(v[i] - v[i + 1]) >= 2)
			return false;

	// slope check : left -> right
	for (int now = 0; now < N - 1; now++) {
		// same height : doesn't need slope
		if (v[now] == v[now + 1])
			continue;

		// left side
		if (v[now] < v[now + 1]) {
			// is able to put ?
			for (int next = now; next > now - X; next--) {
				if (isOut(next) || v[now] != v[next] || leftSlope[next])
					return false;
			}
			// put
			for (int next = now; next > now - X; next--){
				leftSlope[next] = 1;
			}
		}

		// right side
		else{
			// is able to put ?
			for (int next = now + 1; next <= now + X; next++) {
				if (isOut(next) || v[now + 1] != v[next] || rightSlope[next])
					return false;
			}
			// put
			for (int next = now + 1; next <= now + X; next++)
				rightSlope[next] = 1;
		}

		// check whether there is duplicate slope
		for (int now = 0; now < N; now++) {
			if (leftSlope[now] && rightSlope[now])
				return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> TESTCASE;
	for (int tc = 1; tc <= TESTCASE; tc++) {
		cin >> N >> X;

		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> MAP[r][c];

		// row wise check
		int ans = 0;
		for (int col = 0; col < N; col++) {
			vector<int> checkVect;
			for (int row = 0; row < N; row++)
				checkVect.push_back(MAP[row][col]);

			if (check(checkVect))
				ans++;
		}

		// column wise check
		for (int row = 0; row < N; row++) {
			vector<int> checkVect;
			for (int col = 0; col < N; col++)
				checkVect.push_back(MAP[row][col]);

			if (check(checkVect))
				ans++;
		}
		cout << "#" << tc << " " << ans << '\n';
		init();
	}

	return 0;
}