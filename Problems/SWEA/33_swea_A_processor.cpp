#include <iostream>
#include <vector>
#define INF 2134567890
using namespace std;

int TestCase, N, MaxCnt, MinLen;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};
struct POS{ int r, c; };
vector<POS> CpuV;
vector<vector<int>> Map;

bool isClear(POS now, int d){
    while (true){
        if (Map[now.r][now.c]) return false;
        if (now.r == 0 || now.r == N - 1) break;
        if (now.c == 0 || now.c == N - 1) break;
        now = {now.r + dR[d], now.c + dC[d]};
    }
    
    return true;
}

int setLine(POS next, int d, int value){ 
    int step = 0;
    while(true){
        Map[next.r][next.c] = value;
        step++;
        if (next.r == 0 || next.r == N - 1) break;
        if (next.c == 0 || next.c == N - 1) break;
        next = {next.r + dR[d], next.c + dC[d]};
    }
    return step;
}

void dfs(int idx, int cpuCnt, int totalLen){
    if (idx == CpuV.size()){
        if (MaxCnt < cpuCnt){
            MaxCnt = cpuCnt;
            MinLen = totalLen;
        }
        else if (MaxCnt == cpuCnt){
            if (MinLen > totalLen){
                MinLen = totalLen;
            }
        }
        return ;
    }

    for (int i = 0; i < 4; i++){
        POS next = {CpuV[idx].r + dR[i], CpuV[idx].c + dC[i]};
        if (isClear(next, i)){
            dfs(idx + 1, cpuCnt + 1, totalLen + setLine(next, i, 2));
            setLine(next, i, 0);
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

        Map.resize(N, vector<int>(N, 0));
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++){
                cin >> Map[r][c];
                if (0 < r && r < N - 1 && 0 < c && c < N - 1){
                    if (Map[r][c]){ CpuV.push_back({r, c}); }
                }
            }

        dfs(0, 0, 0);

        cout << "#" << tc << " " << MinLen << '\n';

        Map.clear();
        CpuV.clear();
    }

    return 0;
}