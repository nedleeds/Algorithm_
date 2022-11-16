#include <iostream>
#include <unordered_map>
#include <vector>
#define INF 2134567890
using namespace std;

int TestCase, N;
int Min = INF;
int Max = -INF;
int OperatorCnt[4]; // + - * /
string check;
vector<int> Numbers;

void dfs(int now, int totalSum) {
	// level for 'index of Numbers' added to totalSum
	if (now == Numbers.size() - 1) {
		Min = min(Min, totalSum);
		Max = max(Max, totalSum);
		return;
	}

	// branch for signs: +, -, /, *
	for (int i = 0; i < 4; i++) {
		int next = now + 1;
		if (OperatorCnt[i] <= 0) { continue; }
		if (Numbers[next] == 0 && i == 3) { continue; }
		
		OperatorCnt[i]--;

		if 		(i == 0) { dfs(next, totalSum + Numbers[next]); }
		else if (i == 1) { dfs(next, totalSum - Numbers[next]); }
		else if (i == 2) { dfs(next, totalSum * Numbers[next]); }
		else if (i == 3) { dfs(next, totalSum / Numbers[next]); }
		
		OperatorCnt[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(), cout.tie(0);

	freopen("../SampleInput/input.txt", "r", stdin);

	cin >> TestCase;
	for (int tc = 1; tc <= TestCase; tc++) {
		Min = INF;
		Max = -INF;
		Numbers.clear();
		check.clear();

		cin >> N;
		for (int i = 0; i < 4; i++)
			OperatorCnt[i] = 0;

		// operator count setting
		for (int i = 0; i < 4; i++){
			int cnt;
			cin >> cnt;
			OperatorCnt[i] = cnt;
		}

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