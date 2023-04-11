#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Col, Row, K;
struct POS{  int r, c; };
vector<vector<int>> Map, Vst;
queue<POS> Bugs;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = { 0, 0,-1, 1};

void dfs(POS now){
    for (int i = 0; i < 4; i++){
        POS next = {now.r + dR[i], now.c + dC[i]};
        if (0 <= next.r && next.r < Row && 0 <= next.c && next.c < Col){
            if (Vst[next.r][next.c]) continue;
            if (!Map[next.r][next.c]) continue;
            Vst[next.r][next.c] = 1;

            dfs({next});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int testCase;
    cin >> testCase;

    for (int tc = 0; tc < testCase; tc++){
        // M: col, N: row, K: num of cabage
        cin >> Col >> Row >> K; 
        Map.resize(Row, vector<int>(Col));
        Vst.resize(Row, vector<int>(Col));
        
        for (int i = 0; i < K; i++){
            int row, col;
            cin >> col >> row;
            Map[row][col] = 1;
        }

        int group = 0;
        for (int r = 0; r < Row; r++){
            for (int c = 0; c < Col; c++){
                if (Map[r][c] && !Vst[r][c]){
                    ++group;
                    dfs({r, c});
                }
            }
        }

        cout << group << '\n';

        Map.clear();
        Vst.clear();
    }

    return 0;
}