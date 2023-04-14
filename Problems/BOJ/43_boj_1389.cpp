#include <iostream>
#include <queue>
#include <vector>
#define INF 2134567890
using namespace std;

int N, M; // N: # of Users, M: # of friends 
vector<vector<int>> AdjList, Dist;

void bfs(int src, int dst){
    // linked list 의 모든 요소를 탐색하도록 해야한다
    queue<int> q;
    q.push(src);

    while(!q.empty()){

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
        {   // [user -> pal]'s min dist
            for (int pal = 0; pal < N + 1; pal++)
            {   // check each pal
                if (pal != user){
                    bfs(user, pal);
                }
            }
        }
    }

    return 0;
}