#include <iostream>
#include <queue>
using namespace std;

queue<string> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// �縰��� : �ڿ������� �о �Ȱ��� �ܾ�
	// radar, sees
	// �縰��� number : 121, 12421

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
- 1�� �õ����� Ʋ�� : l-26���� break�� ����. ���� 
                     for���� ����ȵǰ� no�� �ݺ������� push
*/
