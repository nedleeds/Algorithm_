#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void reverseQ(void* qP)
{
	queue<int>* Qp = (queue<int> *) qP;
	vector<int> tmp;
	// Q -> vector
	while (!Qp->empty()) {
		tmp.push_back(Qp->front());
		Qp->pop();
	}
	// vector -> Q
	while (!tmp.empty()) {
		Qp->push(tmp.back());
		tmp.pop_back();
	}
}

void operate(void* cmdP, void* inputP) {
	queue<int>* input = (queue<int> *)inputP;
	string cmd = *(string*)cmdP;

	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i] == 'R') {
			// Reverse
			reverseQ(input);
		}
		else if (cmd[i] == 'D') {
			// Delete
			if (input->size() == 0) {
				return;
			}
			else {
				input->pop();
			}
		}
	}
}

void setInputs(void* in) {
	queue<int>* inputs = (queue<int>*) in;
	int dataNum;
	string data;
	cin >> dataNum >> data;
	// remove bracket '[', ']'
	data = data.substr(1, data.size() - 2);

	int start = 0;
	int endIdx = data.find(',');
	// bracket O
	if (endIdx == -1) {
		inputs->push(atoi(data.c_str()));
		return;
	}

	// bracket X
	while (dataNum--) {
		inputs->push(atoi(data.substr(start, endIdx).c_str()));
		start = endIdx + 1;
		endIdx = data.find(',', start);
	}
}

void printResult(queue<int>* qP) {
	if (qP->size()) {
		string ans = "[";
		while (!qP->empty()) {
			ans += to_string(qP->front());
			ans += ",";
			qP->pop();
		}
		ans.pop_back();
		ans += "]\n";
		cout << ans;
		return;
	}
	else {
		cout << "error\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		string cmd;
		cin >> cmd;

		queue<int> inputs;
		setInputs(&inputs);
		operate(&cmd, &inputs);
		printResult(&inputs);
		int de = 1;
	}

	return 0;
}
/*
�Լ� R	- Reverse: �迭�� �ִ� ���� ������ �����´�
�Լ� D	- Delete: ù��° ���� ������ �Լ�
		- �迭�� ����ִ� ���, ���� �߻� [V]

�Լ��� �����ؼ� �ѹ��� ��밡��
ex) AB : A ������ ���� �ٷ� �̾ B ����
	RDD : Reverse - Delete - Delete

�迭�� �ʱⰪ�� ������ �Լ��� �־����� �� ���� ��� ���
*/