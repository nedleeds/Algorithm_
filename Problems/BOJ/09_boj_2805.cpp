#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, h;
	cin >> n >> m;

	vector<int> trees;
	while (n--) {
		cin >> h;
		trees.push_back(h);
	}
	


	return 0;
}