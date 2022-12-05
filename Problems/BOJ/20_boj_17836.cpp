#include <iostream>
#include <vector>
#include <queue>
#define INF 2134567890
using namespace std;

int N, M, T;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};
struct POS {int r, c; };
vector<vector<int>> Map, Vst;

void bfs(){
    queue<POS> q;
    Vst[0][0] = 0;
    q.push({0, 0});

    bool isSord = false;
    while(!q.empty()){
        POS now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            POS next = {now.r + dR[i], now.c + dC[i]};
            if (next.r < 0 || next.r >= N) continue;
            if (next.c < 0 || next.c >= M) continue;
            if (Map[next.r][next.c] == 1 && !isSord) continue;
            if (Map[next.r][next.c] == 2) { isSord = true; }

            if (Vst[next.r][next.c] > Vst[now.r][now.c] + 1){
                Vst[next.r][next.c] = Vst[now.r][now.c] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N >> M >> T;

    Map.resize(N, vector<int>(M, 0));
    Vst.resize(N, vector<int>(M, INF));
    for (int r = 0; r < N; r++){
        for (int c = 0; c < M; c++){
            cin >> Map[r][c];
        }
    }

    bfs();
    int ans =  Vst[N - 1][M - 1];
    if (0 <= ans && ans <= T) { cout << ans << '\n'; }
    else{ cout << "Fail\n"; }

    Map.clear();
    Vst.clear();
    return 0;
}