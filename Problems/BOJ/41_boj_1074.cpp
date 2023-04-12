#include <iostream>
using namespace std;

int N, Row, Col;

int func(int n, int r, int c) {
    // base condition
    if (n == 0) return 0;

    // 0, 1, 2, 3 section 중 어디에 속하는지에 따라 구분하여 재귀호출을 구분지을 것.
    // 호출할 때마다 r과 c가 base condition에 수렴하도록 작성
    // 예를 들어 현재 (r, c) 위치가 2번 section에 있다면, 
    // 0, 1 번 section의 정사각형 개수 만큼은 이미 탐색을 하고 온 것이므로,
    // 2 * 정사각형넓이 = 2 * (half * half) 를 해준 것
    int half = 1 << (n - 1); // 0001 을 n만큼 left shif한다는 의미이므로 2^(n - 1) 을 의미
    if (r < half && c < half) return func(n - 1, r, c);
    if (r < half && c >= half) return (half * half) + func(n - 1, r, c - half);
    if (r >= half && c < half) return 2 * (half * half) + func(n - 1, r - half, c);
    return 3 * (half * half) + func(n - 1, r - half, c - half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);
    
    cin >> N >> Row >> Col;

	cout << func(N, Row, Col) << '\n';
}