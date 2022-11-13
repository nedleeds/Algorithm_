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

void dfs(int row, int cntChanged){
    // condition - checking Map
    if (check()) { 
        Ans = min(Ans, cntChanged); 
        return;  
    }
    
    // condition - dfs stop 
    if (row == D) { return ; }

    // condition - truncation 
    if (cntChanged >= Ans) { return ; }

    for (int mode = 0; mode < 3; mode++){
        if (mode == 0){
            // no injection
            dfs(row + 1, cntChanged);
        }
        else{
            injection(row, mode - 1);
            dfs(row + 1, cntChanged + 1);
            restore(row);
        }
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

        dfs(0, 0);

        cout << "#" << tc << " " << Ans << '\n';
    }

    return 0;
}
/*
D: row
W: col 
K: 합격기준
충격 방향 : 세로방향(row direction)
단면의 모든 세로방향에 대해서 
동일한 특성의 셀들이 K개 이상 연속적으로 있는 경우만 성능검사 통과

[제약사항]
1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 5초
2. 3 ≤ D ≤ 13
3. 1 ≤ W ≤ 20
4. 1 ≤ K ≤ D
5. 셀이 가질 수 있는 특성은 A, B 두 개만 존재한다

[입력]
첫 줄에 총 테스트 케이스의 개수 T가 주어진다.
두 번째 줄부터 T개의 테스트 케이스가 차례대로 주어진다.
각 테스트 케이스의 첫 줄에는 보호 필름의 두께 D, 가로크기 W, 합격기준 K가 차례로 주어진다.
그 다음 D줄에 보호 필름 단면의 정보가 주어진다. 각 줄에는 셀들의 특성 W개가 주어진다. 
(특성 A: 0, 특성 B: 1로 표시된다.)

[풀이]
- 완전탐색(모든 row) + 부분집합( mode: A로/B로/그대로 )
- dfs(level: row, branch: mode)
- 가지치기: dfs(row, cnt)를 적용해서 cnt > 현재의 Ans(최소 변화 횟수)
- 기저조건: row == D
- 확인조건: Tmp 의 col 별 row 연속성 체크(K 활용)
*/