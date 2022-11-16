#include <iostream>
#include <vector>
#define INF 2134567890
using namespace std;

int TestCase, D, W, K;
int Map[13][20];
int Tmp[13][20];
int Ans = INF;

int init(){
    for (int r = 0; r < D; r++)
        for (int c = 0; c < W; c++){
            Map[r][c] = 0;
            Tmp[r][c] = 0;
        }
    Ans = INF;
}

void injection(int row, int value){
    for (int col = 0; col < W; col++)
        Tmp[row][col] = value;
}

void restore(int row){
    for (int col = 0; col < W; col++)
        Tmp[row][col] = Map[row][col];
}

bool check(){
    // check whether # of K values are same or not for the row of each col
    for (int c = 0; c < W; c++){
        bool flag = false;
        for (int r = 0; r <= D - K; r++){
            int currVal = Tmp[r][c];
            int sameCnt = 1;

            for (int dR = 1; dR < K; dR++)
                if (currVal == Tmp[r + dR][c]){ sameCnt++; }

            if (sameCnt == K){
                flag = true;
                break;
            }
        }
        if (flag == false) {return false;}
    }
    return true;
}

void dfs(int row, int cntChanged, int mode){
    if (mode > 0) { injection(row, mode - 1); }

    // condition - checking Map
    if (check()) { 
        Ans = min(Ans, cntChanged); 
        return;  
    }
    if (mode > 0) { restore(row); }

    // condition - dfs stop 
    if (row == D) { return ; }

    // condition - truncation 
    if (cntChanged >= Ans) { return ; }
    
    for (int m = mode + 1; m <= 3; m++){
        dfs(row, cntChanged, m);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> D >> W >> K;

        init();

        for (int row = 0; row < D; row++)
            for (int col = 0; col < W; col++){
                cin >> Map[row][col];
                Tmp[row][col] = Map[row][col];
            }

        dfs(0, 0, 0);

        cout << "#" << tc << " " << Ans << '\n';
    }

    return 0;
}
