#include <iostream>
using namespace std;

int DAT[1000000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    string a, b, c;
    int ans = -1;

    cin >> a >> b;

    bool dat[10] = {false,};
    for (int i = 0; i < a.size(); i++){
        dat[i] = true;
        for ( int j = 0; j < a.size(); j++){
            if (dat[j]) { continue; }
            dat[j] = true;
            for (int k = 0; k < a.size(); k++){
                if (dat[k]) { continue; }
                dat[k] = true;
                for (int l = 0; l < a.size(); l++){
                    if (dat[l]) { continue; }
                    cout << a[i] << a[j] << a[k] << a[l] << '\n';
                    // int num = 
                    // DAT[]
                }
                dat[k] = false;
            }
            dat[j] = false;
        }
        dat[i] = false;
    }

    return 0;
}
/*
1차 시도 : for 문으로 구현하려고 했지만,
         구현하다보니, A가 몇 자리의 정수라는 말이 없음
         4중 for 로 구현 못 할 가능성이 있음 -> dfs
*/