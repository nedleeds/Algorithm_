#include <iostream>
using namespace std;

bool* PrimeArray = new bool[1000001];

void Eratos(int n) {
	if (n <= 1)
		return ;

	// init
	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;
	
	for (int i = 2; i * i <= n; i++) {
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int M, N;
	cin >> M >> N;

	Eratos(N);

	for (int k = M; k <= N; k++) {
		if (PrimeArray[k]) {
			cout << k << '\n';
		}
	}

	return 0;
}