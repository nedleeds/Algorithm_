#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
int DAT[1001];
int Vst[1001];
vector<vector<int>> Map;
vector<int> Nodes, Path;

bool cmp(int a, int b){ return a < b; }
struct cmp2{ bool operator()(int a, int b){ return a > b;} };
priority_queue<int, vector<int>, cmp2> PQ;

void printPath(){
    for (auto x: Path){
        cout << x << " ";
    }
    cout << "\n";
}

void dfs(int lvl, int from, int start){
    if (from == start && lvl != 0){
        return ;
    }

    for (int i = 0 ; i < Nodes.size(); i++){
        int to = Nodes[i];
        if (Map[from][to] == 0) continue;
        if (Vst[to]) continue;
        Path.push_back(to);
        Vst[to] = 1;
        dfs(lvl + 1, to, start);
    }
}

void bfs(int lvl){
    for (int i = 0; i < Nodes.size(); i++){
        int to = Nodes[i];
        if (Vst[to]) continue;
        if (Map[from][to]){
            Path.push_back(to);
        }
        Vst[to] = 1;
    }
    bfs(lvl + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    // N: # of nodes 
    // M: # of edges 
    // V: start node num
    cin >> N >> M >> V;

    Map.resize(N + 1, vector<int>(N + 1));
    for (int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        Map[from][to] = 1;
        Map[to][from] = 1;
        
        if (DAT[from] == 0) {
            DAT[from] = 1;
            Nodes.push_back(from);
        }
        if (DAT[to] == 0){
            DAT[to] = 1;
            Nodes.push_back(to);
        }
    }

    sort(Nodes.begin(), Nodes.end(), cmp);

    Vst[V] = 1;
    Path.push_back(V);
    dfs(0, V, V);
    printPath();

    // init before do bfs
    Path.clear();
    for (int i = 0; i < 1001; i++){
        Vst[i] = 0;
    }

    Vst[V] = 1;
    Path.push_back(V);
    bfs(V);
    printPath();

    Map.clear();

    return 0;
}