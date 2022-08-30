#include <iostream>
using namespace std;

int N, K, ans;
int v[10001];

int binarySearch(long long num) {
	long long left = 1;
	long long right = num;
	long long mid;
	ans = 0;

	while (left <= right) {
		mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += v[i] / mid;
		}
		if (cnt < N) {
			right = mid - 1;
		}
		else{
			left = mid + 1;
			if (ans < mid)
				ans = mid;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> K >> N;

	int M = -2134567890;
	for (int i = 0; i < K; i++) {
		cin >> v[i];
		M = max(M, v[i]);
	}

	int ans = binarySearch(M);

	cout << ans;

	return 0;
}
/*
!!!!! long long 타입 때문에 진심 개고생한 문제 !!!!!

- Binary Search인 것은 진작에 알았음
- K는 1이상 10000이하이고 N은 1이상 1,000,000이하의 정수
- Binary Search에서 999999, 1000000이 들어올경우, 

- 랜선의 길이는 2^31-1보다 작거나 같은 자연수
---> 여기서 파악했어야 했다.
---> int는 -2^31 ~ 2^31 ? 1 범위의 정수
---> 2^31-1 + 2^31-1 = 2^32 - 1 로, int 범위를 벗어남
---> 따라서, left, right, mid 모두 long long으로 선언해줘야함
---> 그렇지 않으면 계속 값이 다르게 나오게 된다

*/