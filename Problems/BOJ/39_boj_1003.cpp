#include <iostream>
#include <vector>
using namespace std;

vector<int> dp0(41);
vector<int> dp1(41);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int testCase;
    cin >> testCase;

    dp0[0] = 1;
    dp0[1] = 0;
    
    dp1[0] = 0;
    dp1[1] = 1;

    for (int i = 2; i < 41; i++){
        dp0[i] = dp0[i - 1] + dp0[i - 2];
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }

    for (int tc = 0; tc < testCase; tc++){
        int idx;
        cin >> idx;
        cout << dp0[idx] <<  " " << dp1[idx] << '\n';
    }

    return 0;
}