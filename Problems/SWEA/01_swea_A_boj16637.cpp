#include <iostream>
#include <vector>
using namespace std;

int totalLen;
string nums;
char arr[22];
vector<int> idxL, idxR;
vector<string> combinations;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> totalLen;
	cin >> nums;

	for (int i = 0; i < nums.length(); i++) {
		arr[2 * i + 1] = nums[i];
	}
	
	for (int i = 0; i <= nums.length() * 2; i++) {
		if (i % 4 == 0) {
			idxL.push_back(i);
		}
		else if ((i - 2) % 4 == 0) {
			idxR.push_back(i);
		}
	}

	int cntPair = 1;
	int l, r;
	for (int selectedCnt = 1; selectedCnt <= 6; selectedCnt++) {
		cntPair = 1;
		while (cntPair != selectedCnt) {
			for (l = 0; l < idxL.size(); l++) {
				arr[idxL[l]] = '(';
				for (r = l; r < idxR.size(); r++) {
					arr[idxR[r]] = ')';
					cntPair++;
					break;
				}
			}
		}
		int de = 1;
	}

	int de = 1;

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