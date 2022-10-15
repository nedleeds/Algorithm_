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

	vector<int> stack, result;
	int cnt = 1;
	int isPass = true;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		// push should be increasing order
		while (cnt <= num) {
			stack.push_back(cnt++);
			result.push_back('+');
		}

		if (stack[stack.size() - 1] == num) {
			stack.pop_back();
			result.push_back('-');
		}
		else {
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