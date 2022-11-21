#include <iostream>
#include <queue>
#define INF 2134567890
#define ROW_SIZE 201
#define COL_SIZE 201
using namespace std;

int TestCase;
int Ans = INF;
int dR[4] = {-1,  0, 1, 0}; // 상, 좌, 하, 우
int dC[4] = { 0, -1, 0, 1};
bool Vst[ROW_SIZE][COL_SIZE];
struct POS { int r, c; } X1, X2;

void resetVst(){
    for (int r = 0; r < ROW_SIZE; r++)
        for (int c = 0; c < COL_SIZE; c++)
            Vst[r][c] = 0;
}

void printMap(){
    for (int r = 90; r < 110; r++)
        for (int c = 90; c < 110; c++)
            cout << Vst[r][c] << ' ';
        cout << '\n';
}

void dfs(POS now, int step, int direction){
    cout << "{" << now.r << ", " << now.c << "}\n";
    if (now.r == X2.r && now.c == X2.c){
        Ans = min(Ans, step);
        return ;
    }

    if (now.r == 0 || now.r == ROW_SIZE - 1) return ;
    if (now.c == 0 || now.c == COL_SIZE - 1) return ;

    for (int i = 0; i < 4; i++){
        if (i%2 == direction){
            POS next = {now.r + dR[i], now.c + dC[i]};
            if (next.r < X1.r - 5 || next.r > X2.r + 5) continue;
            if (next.c < X1.c - 5 || next.c > X2.c + 5) continue;
            if (Vst[next.r][next.c]) continue;

            Vst[next.r][next.c] = true;
            dfs(next, step + 1, (direction ? 0 : 1));
            Vst[next.r][next.c] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> X1.r >> X1.c >> X2.r >> X2.c;
        Ans = INF;
        
        X1.r += 100, X1.c += 100;
        X2.r += 100, X2.c += 100;

        // 1: 가로이동
        // 0: 세로이동
        dfs(X1, 0, 0); 
        resetVst();
        
        Ans = Ans == INF ? -1 : Ans;
        cout << "#" << tc << " " << Ans << '\n';
    }

    return 0;
}

/*
(x1, y1 )에서 (x2, y2)로 이동하려고 한다
(x, y)에서 한 번 이동하면 
    (x + 1, y), 
    (x - 1, y), 
    (x, y + 1), 
    (x, y - 1)로 이동할 수 있다

(x + 1, y), (x - 1, y)로 이동하는 것은 가로 이동, 
(x, y + 1), (x , y - 1)로 이동하는 것은 세로 이동이라고 한다

정우는 그냥 (x1, y1)에서 (x2, y2)로 이동하는 것은 재미가 없다고 생각한다

그래서 이전 이동이 가로 이동이었다면 
이번에는 세로 이동으로 이동하고 
이전 이동이 세로 이동이었다면 
이번에는 가로 이동으로 이동하여 (x1, y1)에서 (x2, y2)로 이동하려고 한다

가장 첫 이동은 어떤 이동 이어도 상관 없다

이 때, 
최소 몇 번의 이동을 해야 (x1, y1)에서 (x2, y2)로 이동할 수 있는지 
구하는 프로그램을 작성하라
*/