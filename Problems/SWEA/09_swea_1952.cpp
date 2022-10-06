#include <iostream>
#define INF 2134567890
using namespace std;

int fees[4];
int days[13];
int minCost = INF;

void dfs(int month, int cost) {
	if (month > 12) {
		minCost = min(minCost, cost);
		minCost = min(minCost, fees[3]);
		return;
	}

	if (days[month]) {
		// day
		dfs(month + 1, cost + fees[0] * days[month]);

		// month
		dfs(month + 1, cost + fees[1]);
	}
	else {
		dfs(month + 1, cost);
	}

	// serial 3 months
	if (month + 3 <= 13) {
		dfs(month + 3, cost + fees[2]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("sample_input.txt", "r", stdin);
	int testCase;
	cin >> testCase;

	for (int test = 1; test <= testCase; test++) {
		minCost = INF;

		for (int i = 0; i < 4; i++)
			cin >> fees[i];

		for (int m = 1; m <= 12; m++) {
			cin >> days[m];
		}

		dfs(0, 0);
		cout << "#" << test << " " << minCost << '\n';
	}


	return 0;
}