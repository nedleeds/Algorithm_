#include <iostream>
using namespace std;

int total;
int ansSheet[1000001];
int movedArr[1000001];
string path;
int popCnt;
int pushCnt;
int flag;

int doOperate() {
	int arr[] = { 1,2,3,4,5,6,7,8 };
	while (!path.empty()) {

	}

}

void comb(int lvl) {
	if (lvl == 2*total) {
		if (pushCnt <= popCnt) {
			flag = 0;
			return;
		}
		else {
			if (doOperate()){
				flag = 1;
				return;
			}
			else flag = 0;
		}
		return;
	}


	for (int branch = 0; branch < 2; branch++) {
		if (branch == 0) popCnt++;
		else pushCnt++;
		path += ('0' + branch);
		
		comb(lvl + 1);

		if (branch == 0) popCnt--;
		else pushCnt--;
		path.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> total;
	for (int i = 0; i < total; i++) {
		cin >> ansSheet[i];
		movedArr[i] = i + 1;
	}

	comb(0);

	return 0;
}