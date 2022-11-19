#include <iostream>
#include <vector>
#define INF 2134567890
using namespace std;

int TestCase, RowMax, ColMax, Ans;
int dR[2][6] = {{-1,-1,-1, 0, 1, 0}, {-1, 0, 1, 1, 1, 0}}; // 1: 한자 '철', 0: 뒤짚은 모양
int dC[2][6] = {{-1, 0, 1, 1, 0,-1}, { 0, 1, 1, 0,-1,-1}};
struct POS{ int r, c; };
vector<vector<int>> Map, Vst;

void printMap(){
    for (int r = 0; r < RowMax; r++){
        for (int c = 0; c < ColMax; c++)
            cout << Vst[r][c] <<' ';
        cout << '\n';
    }
    cout << '\n';
}


void dfs(POS now, int step, int totalSum){
    if (step == 3){
        Ans = max(Ans, totalSum);
        return ;
    }

    for (int i = 0; i < 6; i++){
        POS next = {now.r + dR[now.c % 2][i], now.c + dC[now.c % 2][i]};
        
        // range check
        if (next.r < 0 || next.r >= RowMax) continue;
        if (next.c < 0 || next.c >= ColMax) continue;

        // visit check
        if (Vst[next.r][next.c]) continue;

        Vst[next.r][next.c] = 1;
        dfs(next, step + 1, totalSum + Map[next.r][next.c]);
        Vst[next.r][next.c] = 0;
    }
}

void checkExcept(POS now){
    for (int i = 0; i < 2; i++){
        int cnt = 0;
        int totalSum = Map[now.r][now.c];

        Vst[now.r][now.c] = 1;
        for (int j = 0; j < 6; j++){
            if (j % 2 == i){
                POS next = {now.r + dR[now.c % 2][j], now.c + dC[now.c % 2][j]};
                if (next.r < 0 || next.r >= RowMax) continue;
                if (next.c < 0 || next.c >= ColMax) continue;
                Vst[next.r][next.c] = 1;
                totalSum += Map[next.r][next.c];
                cnt++;
            }
        }
        if (cnt == 3){ 
            Ans = max(Ans, totalSum); 
        }
        for (int j = 0; j < 6; j++){
            if (j % 2 == i){
                POS next = {now.r + dR[now.c % 2][j], now.c + dC[now.c % 2][j]};
                if (next.r < 0 || next.r >= RowMax) continue;
                if (next.c < 0 || next.c >= ColMax) continue;
                Vst[next.r][next.c] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        Ans = -INF;
        cin >> RowMax >> ColMax;
        
        // set the 2D Map, Vst
        Map.resize(RowMax, vector<int>(ColMax, 0));
        Vst.resize(RowMax, vector<int>(ColMax, 0));
        for (int row = 0; row < RowMax; row++)
            for (int col = 0; col < ColMax; col++)
                cin >> Map[row][col];

        for (int r = 0; r < RowMax; r++)
            for (int c = 0; c < ColMax; c++){
                Vst[r][c] = 1;
                dfs({r, c}, 0, Map[r][c]);
                checkExcept({r, c});
                Vst[r][c] = 0;
            }
        cout << "#"<< tc << " " << Ans << "\n";
    }
    return 0;
}
/*
핵심 
-> 닿아 있는 면은 행렬에서 어떻게 색칠 되는지를 파악하는 것이 중요
-> 이걸 먼저 파악했다면, col 이 짝/홀 일 때 모양이 달라지는 것 파악 가능
-> 모양은 6칸으로 이루어져 있다는 것도 파악 가능
-> +) 방항배열로 표현 할 수 없는 '예외 케이스'도 고려해야한다
*/