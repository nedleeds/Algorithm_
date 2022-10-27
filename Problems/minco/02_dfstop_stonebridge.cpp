#include <iostream>
#include <queue>
#include <string>
using namespace std;

string spell;
string devil;
string angel;
string path;
int DAT[27];
int ans;
struct Pos { int row, col; };
queue<Pos> starts;

void SetStarts() {
	char start = spell[0];
	for (int c = 0; c < devil.size(); c++) {
		if (devil[c] == start) {
			starts.push({ 0, c });
		}
		if (angel[c] == start) {
			starts.push({ 1, c });
		}
	}
}

int Toggle(int idx) {
	return idx ^ 1;
}

void Dfs(int row, int col) {
	if (spell == path) {
		ans += 1;
		cout << path << '\n';
		return ;
	}
	
	for (int r = 0; r < 1; r++) {
		if (row == r)
			continue;
		
	}

	path.pop_back();

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> spell >> devil >> angel;

	SetStarts();
	while (!starts.empty()) {
		Pos start = starts.front();
		starts.pop();
		DAT[spell[0] - 'A'] = 1;
		Dfs(start.row, start.col);
		DAT[spell[0] - 'A'] = 0;
	}

	cout << ans << '\n';

	return 0;
}