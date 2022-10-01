#include <iostream>
#include <queue>
using namespace std;

int N;
int MAP[12][12];
int visited[12][12];
int dRow[4] = {-1, 1, 0, 0};
int dCol[4] = { 0, 0,-1, 1};
struct Pos{ int r, c; };
int minDist = 2134567890;
Pos startMonster;
queue<Pos> monsterQ;

void print2DArray(string name, int arr[12][12]){
    cout << "=======" << name <<  "=======\n";
    for (int row = 0; row <= N+1; row++){
        for (int col = 0; col <= N+1; col++ )
            cout << arr[row][col] << ' ';
        cout << '\n';
    }    
}

void printQ(string name, queue<Pos> q){
    int cnt = 0;
    cout << name << ": ";
    while(true){
        Pos curr = q.front();
        q.pop();
        cnt++;
        cout << "{" <<curr.r << ", " << curr.c << "} ";
        q.push(curr);
        if (cnt == q.size())
            break;
    }
    cout << '\n';
}

void setMAP(){
    for (int row = 1; row <= N; row++)
        for (int col = 1; col <= N; col++ ){
            cin >> MAP[row][col];
            if (MAP[row][col] < 0){
                monsterQ.push({row, col});
                int dist = row-1 + col-1;
                if (dist < minDist){
                    minDist = dist;
                    startMonster = {row, col};
                }
            }
        }
    cout << "startMonster: {"<< startMonster.r <<", "<<startMonster.c<<"}\n";
}

void dfs(Pos now){
    // 1. find Monster
    
    for (int i=0; i<4; i++){
        Pos next = {now.r+dRow[i], now.c+dCol[i]};
        if (next.r<=0 || next.c<=0 || next.r>N || next.c>N)
            continue;
        if (visited[next.r][next.c] != 0 )
            continue;
        if (MAP[next.r][next.c] > 0 )
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int testCase;
    cin >> testCase;

    for (int tc = 0; tc < testCase; tc++){
        cin >> N;
        setMAP();
        getMonster(startMonster);
    }
    print2DArray("MAP", MAP);
    printQ("monQ", monsterQ);

    visited[startMonster.r][startMonster.c] = 1;
    dfs(startMonster);

    return 0;
}
// 1 <= T <= 50
// 몬스터: 양수, 고객: 음수
// Quest: 
// 모든 몬스터를 없애고 고객들에게 확인시켜 작업을 완료하는 데 
// 가장 빠른 시간을 구하는 프로그램을 작성해라.

// 1. 몬스터 까지의 최단거리를 구해야된다.
//    --> 입력에서 구함
// 2. 
//  a) start point에서 남은 몬스터 중 가장 가까운 몬스터를 찾고
//  b) start point에서 해당 고객까지 거리를 구해
//  c) a, b 거리 비교 후 짧은 곳 선택
// 

