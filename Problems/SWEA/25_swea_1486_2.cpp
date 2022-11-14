#include<iostream>
using namespace std; 

int N, B;
int height[20];
int minSum; 

void input()
{
    cin >> N >> B;
    for (int i = 0; i < N; i++){
        cin >> height[i];
    }
    minSum = 1e9;
}


void dfs(int level, int prev, int sum)
{
    if (level == N){ return; }

    for (int i = prev + 1; i < N; i++){

        if (sum + height[i] >= B)
            minSum = min(minSum, sum + height[i]); 

        dfs(level + 1, i, sum + height[i]);
    }
}
int main()
{
    freopen("../SampleInput/input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TC; 
    cin >> TC; 
    for (int tc = 1; tc <= TC; tc++)
    {
        input(); 
        
        dfs(0,-1, 0);
        int answer = minSum - B; 
        cout << "#" << tc << " " << answer << "\n";
    }

    return 0; 
}