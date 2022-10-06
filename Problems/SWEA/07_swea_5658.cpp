#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;

int testCase, totalLength, K;
vector<int> duplicates;
string numbers;

const char* getHexa(int start, int totalLength) {
	// the lib is 'square' -> totalLength/4
	string currHexa;
	for (int step = 0; step < (totalLength / 4); step++) {
		int idx = (start + step) % totalLength;
		currHexa += numbers[idx];
	}
	const char* hex = currHexa.c_str();
	return hex;
}

bool isDuplicate(int decValue) {
	for (int i = 0; i < duplicates.size(); i++) {
		int curr = duplicates[i];
		if (curr == decValue)
			return 1;
	}
	duplicates.push_back(decValue);
	return 0;
}

bool cmp(int a, int b) {
	if (a > b) return true;
	if (a < b) return false;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		// get the numbers
		cin >> totalLength >> K >> numbers;
		duplicates.clear();

		vector<int>  decValues;
		for (int i = 0; i < totalLength; i++) {
			// check 1 edge
			int decValue = (int)strtol(getHexa(i, totalLength), NULL, 16);

			if (!isDuplicate(decValue)) {
				decValues.push_back(decValue);
			}
		}
		sort(decValues.begin(), decValues.end(), cmp);
		cout << "#" << tc << " " << decValues[K - 1] << '\n';
	}

	return 0;
}
/*
5
12 10
1B3B3B81F75E
16 2
F53586D76286B2D8
20 14
88F611AE414A751A767B
24 16
044D3EBA6A647B2567A91D0E
28 11
8E0B7DD258D4122317E3ADBFEA99
*/