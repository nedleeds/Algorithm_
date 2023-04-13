#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, V;
int DAT[1001];
int Vst[1001];
vector<vector<int>> Map;
vector<int> Nodes, Path;

bool cmp(int a, int b){ return a < b; }

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
    for (auto x: Path){
        cout << x << " ";
    }
    cout << "\n";
    Path.clear();

    


    Map.clear();

    return 0;
}