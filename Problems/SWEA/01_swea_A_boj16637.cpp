#include <iostream>
#include <vector>
using namespace std;

int n, ans = -2134567890;
string str;

int calculate(int a, int b, char op) {
	if (op == '+')
		a += b;
	else if (op == '-')
		a -= b;
	else if (op == '*')
		a *= b;

	return a;
}

void dfs(int idx, int cur) {
	if (idx >= n) {
		ans = max(ans, cur);
		return;
	}

	char op = idx == 0 ? '+' : str[idx - 1];

	if (idx + 2 < n) {
		int bracket = calculate(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		dfs(idx + 4, calculate(cur, bracket, op));
	}

	dfs(idx + 2, calculate(cur, str[idx] - '0', op));

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> str;

	dfs(0, 0);

	cout << ans;

	return 0;
}
/*
		[ 완탐 문제 ]
- 괄호 안에 들어있는 식 먼저 계산
- 괄호 안에는 연산자가 하나만
- 괄호 안에 괄호는 불가능
- 구할 수 있는 결과의 최대값

수식의 길이 : N (1 <= N <= 19)
수식에 포함된 정수 : 0 이상 9이하
문자열은 정수로 시작
연산자와 정수가 번갈아가면서

ex)
9
3+8*7-9*2

[]3[]+[]8[]*[]7[]-[]9[]*[]2[]
 ( )   ( )   ( )   ( )   ( )

 0    4     8     12    16    (i%4==0) - 좌괄호
[]3  +[]8  *[]7  -[]9  *[]2
  3[]+  8[]*  7[]-  9[]*  2[]
	2     6    10    14    18 ((i-2)%4==0) - 우괄호

아하?

왼쪽 position indices 구해
오른쪽 position indices 구해

전체 길이 * 2 에 대해서
index 0부터 시작

[i%4==0인 경우]
왼쪽 indices 벡터에 넣고

[(i-2)%4==0인 경우]
오른쪽 indices 벡터에 넣고

왼쪽 선택 후 오른쪽 선택
만약, 오른쪽이 선택이 안되었으면 오류

idxL: 00 04 08 12 16
idxR:  02 06 10 14 18

// 가능한 쌍 최대 갯수: idxL
int cntPair;
int l, r;
for( int selectedCnt = 1; selectedCnt <= 6; selectedCnt++){
	while(cntPair != selectedCnt){
		for (l=0; l<idxL.length(); l++){
			arr[l] = '(';
			for (r=l+1; r<idxR.length(); r++){
				arr[r] = ')';
				cntPair++;
				break;
			}
		}
	}
}


--->
*/