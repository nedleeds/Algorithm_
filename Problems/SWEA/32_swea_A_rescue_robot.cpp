#include <iostream>
#include <queue>
#define INF 2134567890
using namespace std;

int TestCase, N;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};
int Fuel[30][30];
int Map[30][30];
struct POS{ int r, c; };

int bfs(){
    queue<POS> q;
    Fuel[0][0] = 0;
    q.push({0, 0});
    
    while(!q.empty()){
        POS now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            POS next = {now.r + dR[i], now.c + dC[i]};
            if (next.r < 0 || next.r >= N) continue;
            if (next.c < 0 || next.c >= N) continue;

            // 낮은 곳으로 이동
            int cost = 0;
            if (Map[next.r][next.c] > Map[now.r][now.c]){
                // 높은 곳으로 이동
                cost = (Map[next.r][next.c] - Map[now.r][now.c]) * 2;
            }
            else if (Map[next.r][next.c] == Map[now.r][now.c]){
                // 높이가 같은 곳으로 이동
                cost = 1;
            }

            int nextFuel = Fuel[now.r][now.c] + cost;

            if (nextFuel < Fuel[next.r][next.c]){
                // 다음에 소모될 연료가 기존 소모량보다 적을 때 업데이트
                Fuel[next.r][next.c] = nextFuel;
                q.push(next);
            }
        }
    }
    return Fuel[N - 1][N - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> N;
        
        // 지도 세팅
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++){
                cin >> Map[r][c];
                Fuel[r][c] = INF;
            }

        int ans = bfs();

        cout << "#" << tc << " " << ans << '\n';

        // 리셋
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++){
                Map[r][c] = 0;
                Fuel[r][c] = INF;
            }
    }

    return 0;
}