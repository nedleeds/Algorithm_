#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int N;
	cin >> N;

	// stack is storage
	vector<int> stack, result;
	int cnt = 1;
	int isPass = true;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		// push should be increasing order
		// ex) cnt == 1, num == 8
		//	   <=> 1 ~ 7 should be in tack
		while (cnt <= num) {
			stack.push_back(cnt++);
			result.push_back('+');
		}

		// if stack[end] == num(input)
		//	  -> pop!
		//	  -> which means 'put the number'
		if (stack[stack.size() - 1] == num) {
			stack.pop_back();
			result.push_back('-');
		}
		else {
			// stop if there's no what we wanna put
			isPass = false;
			break;
		}
	}

	if (isPass) {
		for (int i = 0; i < result.size(); i++)
			cout << (char) result[i] << '\n';
	}
	else {
		cout << "NO\n";
	}

	return 0;
}