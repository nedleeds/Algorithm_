#include <iostream>
#include <vector>
#define INF 2134567890
using namespace std;

int TESTCASE, N;
int MAX = -INF;
int MIN = INF;
int OPCOUNTS;
int DAT[12];
char OP[4] = { '+', '-', '*', '/' };
string strOP;
vector<int> VALUES;
vector<int> INDICES;

int compute() {
	int result = VALUES[0];
	for (int i = 0; i < INDICES.size(); i++) {
		int idx = INDICES[i];
		if (strOP[idx] == '+')
			result = result + VALUES[i + 1];
		else if (strOP[idx] == '-')
			result = result - VALUES[i + 1];
		else if (strOP[idx] == '*')
			result = result * VALUES[i + 1];
		else if (strOP[idx] == '/')
			result = result / VALUES[i + 1];
	}
	return result;
}

void dfs(int lvl) {
	if (lvl == strOP.size()) {
		int v = compute();
		MAX = max(MAX, v);
		MIN = min(MIN, v);
		return;
	}

	for (int i = 0; i < strOP.size(); i++) {
		if (DAT[i]) 
			continue;
		DAT[i] = 1;
		INDICES.push_back(i);
		dfs(lvl + 1);
		DAT[i] = 0;
		INDICES.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> TESTCASE;

	for (int tc = 1; tc <= TESTCASE; tc++) {
		cin >> N;
		strOP = "";
		MIN = INF;
		MAX = -INF;
		VALUES.clear();
		INDICES.clear();
		memset(DAT, 0, 12);
		for (int i = 0; i < 4; i++) {
			int opCnt;
			cin >> opCnt;

			for (int j = 0; j < opCnt; j++)
				strOP += OP[i];
		}
		
		for (int i = 0; i < N; i++) {
			int value;
			cin >> value;
			VALUES.push_back(value);
		}
		dfs(0);

		cout << "#" << tc << ' ' << MAX - MIN << '\n';
	}


	return 0; 
}

/*
10
5
2 1 0 1
3 5 3 7 9
6
4 1 0 0
1 2 3 4 5 6
5
1 1 1 1
9 9 9 9 9
6
1 4 0 0
1 2 3 4 5 6
4
0 2 1 0
1 9 8 6
6
2 1 1 1
7 4 4 1 9 3
7
1 4 1 0
2 1 6 7 6 5 8
8
1 1 3 2
9 2 5 3 4 9 5 6
10
1 1 5 2
8 5 6 8 9 2 6 4 3 2
12
2 1 6 2
2 3 7 9 4 5 1 9 2 5 6 4
*/