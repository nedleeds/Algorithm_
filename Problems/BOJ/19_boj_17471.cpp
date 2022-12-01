#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 213467890
using namespace std;

int TestCase, N, Ans;
vector<int> Population, A, B;
vector<vector<int>> AdjL;

int checkAdj(vector<int> *pGroup){
    vector<int> group = *(vector<int> *)pGroup;
    int cnt = 0;
    int numPeople = 0;
    bool vst[10] = {0};      // 방문한 마을
    bool selected[10] = {0}; // 현재 그룹 내 마을

    for (auto area: group){ 
        numPeople += Population[area];
        selected[area] = true;
    }

    queue<int> q;
    q.push(group[0]);
    vst[group[0]] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < AdjL[now].size(); i++){
            int next = AdjL[now][i];
            if (vst[next]) continue;
            if (selected[next] == false) continue;

            q.push(next);
            vst[next] = true;
        }
    }

    if (cnt == group.size()){ return numPeople; }
    else{ return -1; }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N; // 6
    Ans = INF;

    for (int i = 0; i < N; i++){
        int cnt;
        cin >> cnt;
        Population.push_back(cnt);
    }

    AdjL.resize(N);
    for (int r = 0; r < N; r++){
        int numNear;
        cin >> numNear;
        for (int i = 0; i < numNear; i++){
            int area;
            cin >> area;
            AdjL[r].push_back(area - 1); }
        }
    }

    for (int i = 1; i < (2 << (N - 1)) / 2; i++){
        for (int bit = 0; bit < N; bit++){
            if (i & (1 << bit)){
                A.push_back(bit);
            }
            else{
                B.push_back(bit);
            }
        }

        int cntA = checkAdj(&A);
        int cntB = checkAdj(&B);

        if (cntA != -1 && cntB != -1){
            Ans = min(Ans, abs(cntA - cntB));
        }
        A.clear();
        B.clear();
    }

    Ans = Ans == INF ? -1 : Ans;
    cout << Ans << '\n';

    return 0;
}