#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	int num = 0;
	unordered_map<int, int> nums;

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> n;
	while(n--) {
		cin >> num;
		nums[num] = 1;
	}

	cin >> n;
	while (n--) {
		cin >> num;
		cout << nums[num] << '\n';
	}

	return 0;
}