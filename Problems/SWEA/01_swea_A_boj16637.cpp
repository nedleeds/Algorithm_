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
		[ ��Ž ���� ]
- ��ȣ �ȿ� ����ִ� �� ���� ���
- ��ȣ �ȿ��� �����ڰ� �ϳ���
- ��ȣ �ȿ� ��ȣ�� �Ұ���
- ���� �� �ִ� ����� �ִ밪

������ ���� : N (1 <= N <= 19)
���Ŀ� ���Ե� ���� : 0 �̻� 9����
���ڿ��� ������ ����
�����ڿ� ������ �����ư��鼭

ex)
9
3+8*7-9*2

[]3[]+[]8[]*[]7[]-[]9[]*[]2[]
 ( )   ( )   ( )   ( )   ( )

 0    4     8     12    16    (i%4==0) - �°�ȣ
[]3  +[]8  *[]7  -[]9  *[]2
  3[]+  8[]*  7[]-  9[]*  2[]
	2     6    10    14    18 ((i-2)%4==0) - ���ȣ

����?

���� position indices ����
������ position indices ����

��ü ���� * 2 �� ���ؼ�
index 0���� ����

[i%4==0�� ���]
���� indices ���Ϳ� �ְ�

[(i-2)%4==0�� ���]
������ indices ���Ϳ� �ְ�

���� ���� �� ������ ����
����, �������� ������ �ȵǾ����� ����

idxL: 00 04 08 12 16
idxR:  02 06 10 14 18

// ������ �� �ִ� ����: idxL
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