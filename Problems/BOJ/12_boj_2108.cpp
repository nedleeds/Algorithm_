#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

int op_avg(vector<int>* nums) {
	int s = 0;
	int i = 0;
	for (i = 0; i < nums->size(); i++)
		s += (*nums)[i];

	return round((double)s / i);
}

int op_mid(vector<int> *nums) {
	sort(nums->begin(), nums->end());
	return (*nums)[nums->size() / 2];
}

int op_freq(vector<int>* nums) {
	unordered_map<int, int> DAT, CNT;
	int maxIdx = -2134567890;
	int maxVal = -2134567890;
	int maxCnt = 0;
	vector<int> maxVectors;

	for (auto n : *nums) {
		DAT[n] += 1;
		
		if (DAT[n] >= maxVal) {
			maxVal = DAT[n];
		}
	}


	for (auto n : *nums) {
		if (DAT[n] == maxVal && CNT[n] == 0) {
			maxVectors.push_back(n);
			CNT[n] = 1;
		}
	}

	if (maxVectors.size() == 1)
		return maxVectors[0];
	else
		return maxVectors[1];
}

int op_range(vector<int>* nums) {
	return (*nums)[nums->size() - 1] - (*nums)[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int n;
	cin >> n;

	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	cout << op_avg(&nums) << '\n';
	cout << op_mid(&nums) << '\n';
	cout << op_freq(&nums) << '\n';
	cout << op_range(&nums) << '\n';

	return 0;
}