#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> Map;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N >> M;
    Map.resize(N, vector<int>(N));
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            cin >> Map[r][c];
        }
    }

    int de = 1;
    

    return 0;
}
/*
1차 : 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리
      도시의 치킨 거리는 모든 집의 치킨 거리의 합
*/