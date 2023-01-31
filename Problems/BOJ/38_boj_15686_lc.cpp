#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
struct Pos{int r, c;};
vector<int> Vst;
vector<vector<int>> Map;
vector<Pos> Chicks, Houses;

int dist(int r1, int r2, int c1, int c2){
    return abs(r1 - r2) + abs(c1 - c2);
}

void dfs(int lvl){
    if (lvl == )

    for (int i = 0; i < M; i++){
        if (Vst[i]){ continue; }
        DAT[i] = 1;
        dfs(lvl + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N >> M;
    Map.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            cin >> Map[r][c];
            if (Map[r][c] == 2){ Chicks.push_back({r, c}); }
            else if (Map[r][c] == 1){ Houses.push_back({r, c}); }
        }
    }

    int de = 1;
    for (int i = 1; i <= Chicks.size(); i++){
        Vst.clear();
        Vst.resize(i);
        dfs(0);
    }
    

    return 0;
}
/*
1차 : 치킨 거리 = 집과 가장 가까운 치킨집 사이의 거리
      도시의 치킨 거리 = 모든 집의 치킨 거리의 합
      
      치킨 거리는 집을 기준으로 정해지며, 
      각각의 집은 치킨 거리를 가지고 있다. 
      도시의 치킨 거리는 모든 집의 치킨 거리의 합이다

      두 칸 거리: |r1-r2| + |c1-c2|
      도시 치킨 거리가 min 일때의 치킨 집 개수
      치킨집 1개 -> m 개
      도시 치킨 거리를 구한다
      000001 ~ 111111 까지

      2^m * N(50)개 (치킨집수)-> 2^13: 8천번
      40만 -> 1초안에 연산 가능

*/