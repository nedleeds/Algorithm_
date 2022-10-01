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
!!!!! long long Ÿ�� ������ ���� ������� ���� !!!!!

- Binary Search�� ���� ���ۿ� �˾���
- K�� 1�̻� 10000�����̰� N�� 1�̻� 1,000,000������ ����
- Binary Search���� 999999, 1000000�� ���ð��, 

- ������ ���̴� 2^31-1���� �۰ų� ���� �ڿ���
---> ���⼭ �ľ��߾�� �ߴ�.
---> int�� -2^31 ~ 2^31 ? 1 ������ ����
---> 2^31-1 + 2^31-1 = 2^32 - 1 ��, int ������ ���
---> ����, left, right, mid ��� long long���� �����������
---> �׷��� ������ ��� ���� �ٸ��� ������ �ȴ�

*/