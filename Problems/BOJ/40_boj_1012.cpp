#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, K;
struct POS{  int row, col; };
vector<vector<int>> Map, Vst;
queue<POS> Bugs;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = { 0, 0,-1, 1};

void bfs(){
    int group = 1;

    while(!Bugs.empty()){
        POS now = Bugs.front();
        Bugs.pop();

        for (int i = 0; i < 4; i++){
            POS nxt = { now.row + dR[i], 
                        now.col + dC[i] };
            if (nxt.row < 0 || nxt.row >= N) continue;
            if (nxt.col < 0 || nxt.col >= M) continue;
            if (Vst[nxt.row][nxt.col]) continue;

            Vst[nxt.row][nxt.col] = group;
        }

        group++;
    }

    cout << group << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int testCase;
    cin >> testCase;

    for (int tc = 0; tc < testCase; tc++){
        // M: col, N: row, K: num of cabage
        cin >> M >> N >> K; 
        Map.resize(N, vector<int>(M));
        Vst.resize(N, vector<int>(M));
        
        for (int i = 0; i < K; i++){
            int row, col;
            cin >> col >> row;
            Map[row][col] = 1;
            Bugs.push({row, col});
        }

        bfs();

        Map.clear();
        Vst.clear();
    }

    return 0;
}