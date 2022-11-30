#include <iostream>
#include <vector>
#define INF 2134567890
using namespace std;

int TestCase, N;
int MaxCnt;
int MinLen;
int Map[12][12];
int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};
struct POS{ int r, c; };
vector<POS> CpuV;

bool isClear(POS p, int direction) {
	if (direction == 0) {
		// up
		int row = p.r;
		for (int r = 0; r < row; r++)
			if (Map[r][p.c] != 0)
				return false;
	}
	else if (direction == 1) {
		// down
		int row = p.r;
		for (int r = row + 1; r < N; r++)
			if (Map[r][p.c] != 0)
				return false;
	}
	else if (direction == 2) {
		// left
		int col = p.c;
		for (int c = 0; c < col; c++)
			if (Map[p.r][c] != 0)
				return false;
	}
	else if (direction == 3) {
		// right
		int col = p.c;
		for (int c = col + 1; c < N; c++)
			if (Map[p.r][c] != 0)
				return false;
	}
	else {
		cout << "direction is wrong\n";
	}
	return true;
}

int checkLine(POS p, int direction, int mode) {
    int step = 0;
    if (direction == 0){
        // up
        for (int row = p.r; row >= 0; row--){
            Map[row][p.c] = mode;
            step++;
        }
    }
    else if (direction == 1){
        // down
        for (int row = p.r; row < N; row++){
            Map[row][p.c] = mode;
            step++;
        }
    }
    else if (direction == 2){
        // left
        for (int col = p.c; col >= 0; col--){
            Map[p.r][col] = mode;
            step++;
        }
    }
    else if (direction == 3){
        // right
        for (int col = p.c; col < N; col++){
            Map[p.r][col] = mode;
            step++;
        }
    }
    
    return step;
}

void dfs(int idx, int cpuCnt, int totalLen){
    if (idx == CpuV.size()){
        if (cpuCnt > MaxCnt){
            MaxCnt = cpuCnt;
            MinLen = totalLen;
        }
        else if (cpuCnt == MaxCnt) {
            if (MinLen > totalLen)
                 MinLen = totalLen;
        }
        return ;
    }

    // 4 방향
    for (int i = 0; i < 4; i++){
        POS next = { CpuV[idx].r + dR[i],  CpuV[idx].c + dC[i] };
        if (Map[next.r][next.c] != 0)
            continue;

        if (isClear(next, i)){
            dfs(idx + 1, cpuCnt + 1, totalLen + checkLine(next, i, 2));
            checkLine(next, i, 0);
        }
    }
    dfs(idx + 1, cpuCnt, totalLen);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> N;
        MaxCnt = -INF, MinLen = INF;

        // input
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++){
                cin >> Map[r][c];
                if ( 0 < r && r < N &&  0 < c && c < N && Map[r][c])
                        CpuV.push_back({r, c});
            }

        dfs(0, 0, 0);

        cout << "#" << tc << " " << MinLen <<'\n';

        // reset
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                Map[r][c] = 0;
        CpuV.clear();
    }

    return 0;
}