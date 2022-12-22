#include <iostream>
#include <vector>
using namespace std;

int N, L, R, X, Ans;
bool Vst[16];
vector<int> Problems, Path;

void dfs(int lvl, int cnt, int minV, int maxV, int scoreSum){
    if (lvl == N){
        if (maxV - minV >= X and cnt >= 2){
            if (L <= scoreSum and scoreSum <= R){
                Ans++;
            }
        }
        return;
    }

    dfs(lvl + 1, cnt + 1, min(minV, Problems[lvl]), max(maxV, Problems[lvl]), scoreSum + Problems[lvl]);
    dfs(lvl + 1, cnt, minV, maxV, scoreSum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N >> L >> R >> X;

    Problems.resize(N);
    for (int i = 0; i < N; i++){
        cin >> Problems[i];
    }

    dfs(0, 0, 2e9, -2e9, 0);

    cout << Ans << '\n';

    return 0;
}