#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

double op_avg(vector<int> nums) {
	int s = 0;
	for (int i = 0; i < nums.size(); i++)
		s += nums[i];

	return round(s / nums.size());
}

int op_mid(vector<int> nums) {
	return nums[nums.size()/2];
}
int op_most(vector<int> nums) {
	unordered_map<int, int> cntTable;
	for (int i = 0; i < nums.size(); i++) {
		cntTable[nums[i]] += 1;
	}
	
	int maxIdx = 0;
	int maxVal = -213467890;
	for (auto it : cntTable) {

	}

	return 0;
}
int op_range(vector<int> nums) {
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int N;
	cin >> N;

	vector<int> nums;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	cout << op_avg(nums) << '\n';
	cout << op_mid(nums);
	//cout << op_most(nums);
	//cout << op_range(nums);
	

	return 0;
}