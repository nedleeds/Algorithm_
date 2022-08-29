#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int num;
	cin >> num;

	string start = "666";
	int cnt = 0;
	while (1) {
		// find "666" 있으면 cnt+1;
		if (start.find("666") != -1) {
			cnt++;
			if (num == cnt)
				break;
		}
		// 없으면 -> 숫자 증가
		// string 2 num
		int n = stoi(start);

		// num 2 string
		n += 1;
		start = to_string(n);
	}
	cout << start << '\n';
	return 0;
}
/*
c++ library
<string>
stoi() : string to integer
stod() : string to double
stof() : string to float
to_string(number) : make number string
*/