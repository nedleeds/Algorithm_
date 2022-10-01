#include <cstdio>
#include <vector>
using namespace std;

int ining, ans;
vector<int> order;
vector<vector<int>> vvi;
bool inOrder[9] = {true, false, false, false, false, false, false, false, false};

void run()
{
    int cur_hitter = 0, score = 0;
    for (int curIning = 0; curIning < ining; curIning++)
    {
        int outCount = 0;
        bool bases[4] = {false, }; // 0:Home
        while (outCount < 3)
        {
            int hit = vvi[curIning][order[cur_hitter]];
            bases[0] = true;
            switch (hit)
            {
            case 0:
                outCount++;
                break;
            
            default:
                for (int i=3; 0<=i; i--) if (bases[i])
                {
                    if (hit + i > 3) score++;
                    else bases[hit + i] = true;
                    bases[i] = false;
                }
            }
            cur_hitter = (cur_hitter+1)%9;
        }
    }
    
    ans = ans>score?ans:score;
}

void dfs(int cnt)
{
    if (cnt == 9) run();
    else
    {
        if (cnt == 3)
        {
            order.push_back(0);
            dfs(cnt+1);
            order.pop_back();
        }
        else
        {
            for (int i=0; i<9; i++)
            {
                if (inOrder[i]) continue;
                inOrder[i] = true;
                order.push_back(i);
                dfs(cnt+1);
                inOrder[i] = false;
                order.pop_back();
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &ining);
    vvi.assign(ining, vector<int>(9));
    for (int i=0; i<ining; i++) for (int j=0; j<9; j++) scanf("%d", &vvi[i][j]);

    dfs(0);

    printf("%d\n", ans);

    return 0;
}