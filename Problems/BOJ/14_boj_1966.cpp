#include <iostream>
#include <algorithm>
#define INF 2134567890
using namespace std;

int s = 0;
int minCnt = INF;
int Dp[5001]; // # of plastic bag

void dp(int n) {
	// bottom - up
	// Dp[] has '# of plastic bag
	Dp[3] = 1;
	Dp[5] = 1;
	for (int idx = 6; idx <= n; idx++){
		// if 3 steps before idx has a value then add 1 to it.
		if (Dp[idx - 3]) 
			Dp[idx] = Dp[idx-3] + 1;
		
		// if 5 steps before idx also has a value,
		// then, add min(Dp[idx], Dp[idx-5] + 1).
		/// !! Dp[idx] <-- already update above condition !!
		// else, add Dp[idx - 5] + 1
		if (Dp[idx - 5]){
			Dp[idx] = Dp[idx] ? min(Dp[idx], Dp[idx-5] + 1) : Dp[idx-5] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen("../SampleInput/input.txt", "r", stdin);

	int n;
	cin >> n;

	dp(n);

	cout << (Dp[n] == 0 ? -1 : Dp[n]) << endl;

	return 0;
}