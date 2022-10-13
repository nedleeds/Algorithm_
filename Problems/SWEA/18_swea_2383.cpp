#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 2134567890
using namespace std;

int TESTCASE, N;
int ANS = INF;
int MAP[10][10];
struct Pos { int r, c; };
struct Person {
	int r, c;
	int stair;
};
vector<int> TIME2STAIR[2];
vector<Pos> STAIRS;
vector<Person> PEOPLE;

void init(int m[10][10]) {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			m[r][c] = 0;

	PEOPLE.clear();
	STAIRS.clear();
	ANS = INF;
}

int getTotalTime(int sIdx) {
	// compute times for going down
	vector<int> timeGo = TIME2STAIR[sIdx];
	int timeDown = MAP[STAIRS[sIdx].r][STAIRS[sIdx].c];

	if (timeGo.size() == 0)
		return 0;
	else if (timeGo.size() <= 3)
		return timeGo[timeGo.size() - 1] + timeDown;
	else {
		// make waiting Q
		int totalTime = 0;
		queue<int> waitQ;
		waitQ.push(timeGo[0]);
		waitQ.push(timeGo[1]);
		waitQ.push(timeGo[2]);
		int i = 3;
		while (!waitQ.empty()) {
			int frontGoTime = waitQ.front();
			int frontTime = frontGoTime + timeDown;
			waitQ.pop();

			if (i < timeGo.size()) {
				if (frontTime > timeGo[i]) {
					// idx -> need to wait : update idx's time
					timeGo[i] += frontTime - timeGo[i];
				}
				// else{}: idx doesn't need to wait.
				waitQ.push(timeGo[i]);

				i++;
			}
			// ** last person's frontTime == totalTime **
			totalTime = frontTime;
		}
		return totalTime;
	}
}

void splitStairs() {
	// time to the each stair
	TIME2STAIR[0].clear();
	TIME2STAIR[1].clear();

	for (int i = 0; i < PEOPLE.size(); i++) {
		Person p = PEOPLE[i];
		int s = p.stair;
		int arriveTime = abs(p.r - STAIRS[s].r) + abs(p.c - STAIRS[s].c);
		TIME2STAIR[s].push_back(arriveTime);
	}
	// shortest first
	sort(TIME2STAIR[0].begin(), TIME2STAIR[0].end());
	sort(TIME2STAIR[1].begin(), TIME2STAIR[1].end());
}

void dfs(int idx) {
	// make permutation of PEOPLE 
	// PEOPLE: <0 or 1>, stair numbers
	if (idx == PEOPLE.size()) {
		splitStairs();
		int s0 = getTotalTime(0);
		int s1 = getTotalTime(1);
		int endTime = max(s0, s1);
		ANS = min(ANS, endTime);
		return;
	}

	for (int i = 0; i < 2; i++) {
		PEOPLE[idx].stair = i;
		dfs(idx + 1);
		PEOPLE[idx].stair = 0;
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
		
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++) {
				cin >> MAP[r][c];
				// set people
				if (MAP[r][c] == 1) {
					PEOPLE.push_back({r, c, 0});
				}
				// set stairs
				else if (MAP[r][c] >= 2) {
					STAIRS.push_back({ r, c });
				}
			}

		dfs(0);

		// we can go down after 1 minute from arriving stair
		cout << "#" << tc << " " << ANS + 1 << "\n";
		init(MAP);
	}


	return 0;
}