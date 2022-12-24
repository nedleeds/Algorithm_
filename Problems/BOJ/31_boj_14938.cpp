#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, R;
int Ans = -2e9;
struct Area{ int to, cost; };
vector<int> Items, Vst;
vector<vector<Area>> AdjList;

struct cmp{
    bool operator()(int a, int b){
        if (a > b) return true;
        if (a < b) return false;
        return false;
    }
};

int dijkstra(int start){
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(start);
    Vst[start] = 0;

    while(!pq.empty()){
        int now = pq.top();
        pq.pop();

        for (int i = 0; i < AdjList[now].size() - 1; i++){
            Area next = AdjList[now][i];
            if (Vst[now] + next.cost < Vst[next.to]){
                Vst[next.to] = Vst[now] + next.cost;
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N >> M >> R;

    Items.resize(N + 1);
    for (int i = 1; i <= N; i++){
        cin >> Items[i];
    }

    AdjList.resize(N + 1, vector<Area>());
    for (int i = 0; i < R; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        AdjList[from].push_back({to, cost});
    }

    for (int start = 1; start <= 5; start++){
        Vst.resize(N, 2e9);
        dijkstra(start);
        Vst.clear();
    }

    cout << Ans << '\n';

    return 0;
}