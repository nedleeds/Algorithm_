#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int TestCase;
int DAT[51];
vector<int> AdjL[51];

bool bfs(int nodeStart, int nodeEnd)
{
    queue<int> q;
    q.push(nodeStart);
    DAT[nodeNow] = 1;

    bool adjFlag = false;
    while(!q.empty())
    {
        int nodeNow = q.front();
        q.pop();

        if (nodeNow == nodeEnd)
            adjFlag = true;

        for (int i = 0; i < AdjL[nodeNow].size(); i++)
        {
            int nodeNext = AdjL[nodeNow][i];
            if (DAT[nodeNext]) continue;

            DAT[nodeNext] = 1;
            q.push(nodeNext);
        }
    }
    
    return adjFlag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++)
    {
        int cntV, cntE;
        int nodeS, nodeE;
        cin >> cntV >> cntE;
        
        for (int i = 0; i < cntE; i++)
        {
            int from, to;
            cin >> from >> to;
            AdjL[from].push_back(to);
        }

        cin >> nodeS >> nodeE;

        int ans = bfs(nodeS, nodeE) ? 1 : 0;

        cout << "#" << tc << " " << ans << '\n';
        
        for (int i = 0; i < 51; i++){
            DAT[i] = 0;
            AdjL[i].clear();
        }
    }

    return 0;
}