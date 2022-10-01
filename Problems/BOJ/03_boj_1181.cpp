#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> strings;
unordered_map<string, int> DAT;

bool cmp(string a, string b) {
	if (a.length() < b.length()) return true;
	if (a.length() > b.length()) return false;
	if (a < b) return true;
	if (a > b) return false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N;
	cin >> N;

	for (int i=0; i<N; i++){
		string s;
		cin >> s;
		
		if (DAT.find(s) == DAT.end()){
			strings.push_back(s);
			DAT[s] = 1;
		}
	}

	sort(strings.begin(), strings.end(), cmp);

	for (int i = 0; i < strings.size(); i++) {
		cout << strings[i] << '\n';
	}

	return 0;
}