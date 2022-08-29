#include <iostream>
#include <queue>
using namespace std;

queue<string> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// 펠린드롬 : 뒤에서부터 읽어도 똑같은 단어
	// radar, sees
	// 펠린드롬 number : 121, 12421

	while (true) {
		string num;
		cin >> num;
		if (num != "0") {
			int flag = 1;
			for (int i = 0; i < num.length() / 2; i++) {
				char a = num[i];
				char b = num[num.length() - 1 - i];
				if (a != b) {
					cout << "no\n";
					flag = 0;
					break;
				}
			}
			if (flag != 0)
				cout << "yes\n";
		}
		else {
			break;
		}
	}

	return 0;
}

/*
- 1차 시도에서 틀림 : l-26에서 break를 안함. 따라서 
                     for문이 종료안되고 no를 반복적으로 push
*/
