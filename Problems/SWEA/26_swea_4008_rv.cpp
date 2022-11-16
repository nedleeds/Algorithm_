#include <iostream>
#include <unordered_map>
#include <vector>
#define INF 2134567890
using namespace std;

int TestCase, N, numOPs;
int Min = INF;
int Max = -INF;
int OperatorCnt[4];
vector<int> Numbers;
int DAT[12];

void dfs(int idx, int totalSum) {
	if (idx == Numbers.size()) {
		if (Min > totalSum) { Min = totalSum; }
		if (Max < totalSum) { Max = totalSum; }
		return;
	}

	// branch for signs: +, -, /, *
	for (int i = 0; i < 4; i++) {
		if (OperatorCnt[i] == 0) continue;

		OperatorCnt[i]--;

		if (i == 0) { dfs(idx + 1, totalSum + Numbers[idx]); }
		else if (i == 1){ dfs(idx + 1, totalSum - Numbers[idx]); }
		else if (i == 2) { dfs(idx + 1, totalSum / Numbers[idx]); }
		else if (i == 3) { dfs(idx + 1, totalSum * Numbers[idx]); }
		
		OperatorCnt[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(), cout.tie(0);

	freopen_s(new FILE*, "./SampleInput/input.txt", "r", stdin);

	cin >> TestCase;
	for (int tc = 1; tc <= TestCase; tc++) {
		Min = INF;
		Max = -INF;
		Numbers.clear();

		cin >> N;
		for (int i = 0; i < 4; i++)
			OperatorCnt[i]++;


		// set the input numbers
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			Numbers.push_back(num);
		}

		dfs(0, Numbers[0]);

		cout << "#" << tc << " " << Max - Min << '\n';
	}



	return 0;
}