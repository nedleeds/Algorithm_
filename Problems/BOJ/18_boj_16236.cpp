#include <iostream>
#include <queue>
using namespace std;

int N;
int Map[20][20];
int dR[4] = {-1, 1, 0, 0};
int dC[4] = { 0, 0,-1, 1};
struct POS{ int r, c, dist; } Shark, Fish;

int getDist(POS *shark, POS fish){
    return abs(shark->r - fish.r) + abs(shark->c - fish.c);
}

bool operator <(POS fishA, POS fishB){
    if (fishA.dist < fishB.dist) return true;
    if (fishA.dist > fishB.dist) return false;

    if (fishA.r < fishB.r) return true;
    if (fishA.r > fishB.r) return false;

    if (fishA.c < fishB.c) return true;
    if (fishA.c > fishB.c) return false;

    return false;
}
priority_queue<POS> Fishes;

void dfs(POS *nowShark, int sharkSize){

    for (int i = 0; i < 4; i++){
        POS nextShark = {nowShark->r + dR[i], nowShark->c + dC[i]};
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);
    
    cin >> N;
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            cin >> Map[r][c];
            if (Map[r][c] == 9){
                Shark = {r, c};
            }

        }
    }
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            if (Map[r][c] >=1 && Map[r][c] <= 6){
                Fish = {r, c};
                Fish.dist = getDist(&Shark, Fish);
                Fishes.push(Fish);
            }
        }
    }
    
    int de = 1;

    return 0;
}
/*
공간    : NxN 크기
       : 0 - 빈칸, 9 - 아기상어 , 1~6 - 물고기 크기

물고기   : M마리
       : 1칸당 물고기 최대 1마리
       : 크기 자연수

아기상어 : 1마리
       : 처음 크기 - 2
       : 1초에 상하좌우로 인접한 한 칸 씩 이동 => 방향배열
       : 자신의 크기보다 작은 물고기만 먹는다 => 도착하면 값 비교해서 baby 보다 작으면 먹음
       : 크기가 같은 물고기 - 먹을 수는 없지만 지나갈 수 있다 => 방향배열 if 문 > 면 continue
       - 더 이상 먹을 수 있는 물고기가 공간에 없으면 -> 엄마 상어에게 도움 요청 
            => for 문 완료 후 pass cnt = 0 인 경우 : 그 동안 잡아먹은 물고기 수 출력하면서 탈출
       - 먹을 수 있는 물고기 = 1마리 
          -> 먹으러 간다(이동) -> 0 마리는 이동 불가
       - 먹을 수 있는 물고기 > 1마리 => 'bfs'
          -> "가장 가까운" 물고기 먹으러 간다 => '상어 노드'~'물고기' bfs 로 -> queue를 heap+sort(Pos)
          -> 거리: 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때
                  지나야 하는 칸의 갯수의 최솟값
          -> 거리가 가까운 물고기가 많다면, 
             -> 가장 위에 있는 물고기 => (row Min)
             -> 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다 => (col Min)
        - 아기 상어의 이동은 1초, 물고기 먹는데 걸리는 시간은 없다
        - 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, "동시에 먹음 "
        - "물고기를 먹으면 그 칸은 빈 칸이 된다"
        - 아기 상어는 "자신의 크기"와 "같은 수"의 물고기를 먹을 때 마다 크기가 1증가한다
          -> 1이면 1마리 먹고 증가, 2면 2마리 먹고 증가 ...
        - 공간(map)이 주어졌을 때, 
          아기 상어가 몇 초 동안 "엄마 상어에게 도움을 요청하지 않고"
          물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오


*/