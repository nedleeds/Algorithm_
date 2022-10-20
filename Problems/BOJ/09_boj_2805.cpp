#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2134567890
#define INT long long
using namespace std;

INT N, M, H, ANS;
vector<INT> trees;

INT sum_diff(INT mid) {
	INT tot = 0;
	for (INT i = 0; i < N; i++) {
		if (trees[i] > mid)
			tot += trees[i] - mid;
	}
	return tot;
}

void binarySearch(INT left, INT right) {
	// left, right, mid -> "tree height"

	while (left <= right) {
		INT mid = (left + right) / 2;
		if (sum_diff(mid) >= M) {
			// renew left
			if (ANS < mid) {
				ANS = mid;
			}
			left = mid + 1;
		}
		else{
			// renew right
			right = mid - 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> N >> M;
	// 0 < N <= 10^6
	// 0 < M <= 2 * 10^9 
	// Type should be changed from 'int' to 'long long'
	
	INT hMax = -INF;
	INT n = N;
	while (n--) {
		cin >> H;
		trees.push_back(H);
		hMax = max(hMax, H);
	}

	binarySearch(0, hMax);

	cout << ANS << '\n';

	return 0;
}