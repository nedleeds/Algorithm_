#include <iostream>
#include <vector>
#include <string>
using namespace std;

void operate(string cmd, void* stackP, int num){
	vector<int> *stack = (vector<int> *) stackP;

	if (cmd == "push"){
		stack->push_back(num);
	}
	else if (cmd == "pop"){
		int num = stack->empty()? -1 : stack->back();
		if (num != -1)
			stack->pop_back();
		cout << num << '\n';
	}
	else if (cmd == "size"){
		cout << stack->size() << '\n';
	}
	else if (cmd =="empty"){
		int isEmpty = stack->empty() ? 1 : 0;
		cout << isEmpty << '\n';
	}
	else if (cmd == "top"){
		int num = stack->empty()? -1 : stack->back();
		cout << num << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "./sample_input.txt", "r", stdin);

	int n;
	cin >> n;
	
	vector<int> stack;
	for (int i = 0; i <= n; i++) {
		string s;
		getline(cin, s);

		int idx = s.find(' ');
		string cmd = s.substr(0, idx);

		int num = 0;
		if (idx != - 1)
			num = atoi(s.substr(idx + 1, s.size()-1).c_str());

		operate(cmd, &stack, num);
	}

	return 0;
}