#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 2134567890
using namespace std;

int N, M; // N: # of Users, M: # of friends 
int MinDist = INF;
int Ans;
vector<int> Dist, Vst;
vector<vector<int>> AdjList;

void bfs(int start){
    // dijkstra 로 체크
    Dist.resize(N + 1, INF);
    Vst.resize(N + 1, 0);

    queue<int> q;
    q.push(start);
    Dist[start] = 0;
    Vst[start] = 1;

    while(!q.empty()){
        int user = q.front();
        q.pop();

        for (int i = 0; i < AdjList[user].size(); i++){
            int pal = AdjList[user][i];
            if (Vst[pal]){
                continue;
            }
            q.push(pal);
            Dist[pal] = min(Dist[pal], Dist[user] + 1);
            Vst[pal] = 1;
        }
    }

    int totalDist = 0;
    for (auto x: Dist){
        if (x != INF){
            totalDist += x;
        }
    }

    if (MinDist > totalDist){
        MinDist = totalDist;
        Ans = start;
    }

    Dist.clear();
    Vst.clear();
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N >> M;

    AdjList.resize(N + 1);
    for (int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        AdjList[from].push_back(to);
        AdjList[to].push_back(from);
    }

    for (int user = 1; user <= N; user++)
    {   
        if (AdjList[user].size() != 0)
        {   
            bfs(user);
        }
    }

    cout << Ans << '\n';

    return 0;
}