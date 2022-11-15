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
함수 R	- Reverse: 배열에 있는 수의 순서를 뒤집는다
함수 D	- Delete: 첫번째 수를 버리는 함수
		- 배열이 비어있는 경우, 에러 발생 [V]

함수는 조합해서 한번에 사용가능
ex) AB : A 수행한 다음 바로 이어서 B 수행
	RDD : Reverse - Delete - Delete

배열의 초기값과 수행할 함수가 주어졌을 때 최종 결과 출력
*/