#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 2134567890
using namespace std;

int N, M; // N: # of Users, M: # of friends 
int Vst[101];
vector<vector<int>> AdjList, Dist;

void bfs(int start){
    // dijkstra 로 체크
    queue<int> q;
    q.push(start);

    Dist.assign(N + 1, vector<int>(N + 1, INF));
    Vst[start] = 1;

    while(!q.empty()){
        int user = q.front();
        q.pop();

        for (int i = 0; i < AdjList[user].size(); i++){
            int pal = AdjList[user][i];
            if (Vst[pal]) continue;
            Dist[user][pal] = 1;
            q.push(pal);
        }

    }
    
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N >> M;
    
    AdjList.resize(N + 1);
    Dist.assign(N + 1, vector<int>(N + 1, INF));
    for (int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        AdjList[from].push_back(to);
        AdjList[to].push_back(from);
    }

    for (int user = 0; user < AdjList.size(); user++)
    {   
        if (AdjList[user].size() != 0)
        {   
            // [user -> pal]'s min dist
            // pal check
            cout << "[" << user << "]";
            for (auto x : AdjList[user]){
                cout << x << ' ';
            }
            cout << '\n';
            bfs(user);
        }
    }

    return 0;
}