#include <iostream>
using namespace std;
int rowMax, colMax;
string board[50];
string chess1[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string chess2[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int compare(string board[50]) {
	// 시작점이 바뀜
	// 0 ~ rowMax - 8까지
	int m = 2134567890;
	for (int r = 0; r <= rowMax - 8; r++) {
		for (int c = 0; c <= colMax - 8; c++) {
			// 비교 시작
			int cntDiff1 = 0;
			int cntDiff2 = 0;
			for (int row = r; row < r + 8; row++) {
				for (int col = c; col < c + 8; col++) {
					if (board[row][col] != chess1[row - r][col - c]) {
						cntDiff1++;
					}
					if (board[row][col] != chess2[row - r][col - c]) {
						cntDiff2++;
					}

				}
			}
			int minDiff = min(cntDiff1, cntDiff2);
			if (m > minDiff) {
				m = minDiff;
			}
		}
	}
	
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	
	cin >> rowMax >> colMax;
	for (int r = 0; r < rowMax; r++) {
		string s;
		cin >> s;
		board[r] = s;
	}

	int ans = compare(board);
	cout << ans << '\n';

	return 0;
}