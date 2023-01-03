#include <iostream>
#include <vector>
using namespace std;

struct Var{ int num; char op; };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int n;
    string s;
    cin >> n >> s;

    vector<Var> variables;    
    for (int i = 0; i < n; i++){
        if ((i % 2)){
            variables.push_back({0, s[i]});
        }
        else{
            variables.push_back({s[i] - '0', '0'});
        }
    }

    // m : 연산자 수
    // 연산자 수를 기준으로 비트마스크 진행
    int m = (n - 1) / 2;
    for (int i = 0; i < (1 << m); i++){
        bool ok = true;
        for (int j = 0; j < m - 1; j++){
            // 연속된 연산자 2개를 선택하는 경우 -> 제외
            if ((i & (1 << j)) && (i & (1 << (j + 1)))){ ok = false; }
        }

        for (int j = 0; j < m)
        
        // 선택된 연산자는 먼저 계산 진행
        int compute = 0;
            

        }
    }


    return 0;
}