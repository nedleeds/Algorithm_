#include <iostream>
#include <vector>
#define INF 2134567890
using namespace std;

int TestCase, N, K, Ans;
int Map[8][8];
int Vst[8][8];
int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};
struct POS{ int r, c; };
vector<POS> Heighest;

void reset(){
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++){
            Map[row][col] = 0;
            Vst[row][col] = 0;
        }

    Heighest.clear();
    Ans = -INF;
}

void dfs(POS now, int sumStep, bool isDigged){
    int nowHeight = Map[now.r][now.c];
    Ans = max(Ans, sumStep);

    for (int i = 0; i < 4; i++){
        POS next = {now.r + dR[i], now.c + dC[i]};
        int nextHeight = Map[next.r][next.c];

        if (next.r < 0 || next.r >= N) continue;
        if (next.c < 0 || next.c >= N) continue;
        if (Vst[next.r][next.c]) continue;
        
        bool recoverDigFlag = false;
        if (nextHeight >= nowHeight){
            if (nextHeight - K >= nowHeight) continue;
            if (nextHeight - K < nowHeight){
                if (isDigged) { continue; }
                else { 
                    Map[next.r][next.c] = nowHeight - 1; 
                    recoverDigFlag = true;
                    isDigged = true;
                }
            }   
        }

        Vst[next.r][next.c] = 1;
        dfs(next, sumStep + 1, isDigged);
        
        // recover 
        Vst[next.r][next.c] = 0;
        if (recoverDigFlag){
            Map[next.r][next.c] = nextHeight; 
            isDigged = false;
        }   
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> N >> K;

        // set Map
        int MaxH = -INF;
        for (int row = 0; row < N; row++){
            for (int col = 0; col < N; col++){
                cin >> Map[row][col];

                if (MaxH < Map[row][col]){
                    Heighest.clear();
                    MaxH = Map[row][col];
                    Heighest.push_back({row, col});
                }

                else if (MaxH == Map[row][col])
                    Heighest.push_back({row, col});
            }
        }
        
        // check route for Topest position
        for (int i = 0; i < Heighest.size(); i++){
            Vst[Heighest[i].r][Heighest[i].c] = 1;
            dfs(Heighest[i], 1, 0);
            Vst[Heighest[i].r][Heighest[i].c] = 0;

        }
        cout << "#" << tc << " " << Ans << '\n';
        reset();
    }

    return 0;
}
/*
[제약 사항]
1. 시간 제한 : 최대 51개 테스트 케이스를 모두 통과하는 데 C/C++/Java 모두 3초
2. 지도의 한 변의 길이 N은 3 이상 8 이하의 정수이다. (3 ≤ N ≤ 8)
3. 최대 공사 가능 깊이 K는 1 이상 5 이하의 정수이다. (1 ≤ K ≤ 5)
4. 지도에 나타나는 지형의 높이는 1 이상 20 이하의 정수이다
5. 지도에서 가장 높은 봉우리는 최대 5개이다
6. 지형은 정수 단위로만 깎을 수 있다
7. 필요한 경우 지형을 깎아 높이를 1보다 작게 만드는 것도 가능하다
*/