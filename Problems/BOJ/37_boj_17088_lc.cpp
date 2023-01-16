#include <iostream>
#include <vector>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N;
    vector<int> array(N);
    for (int i = 0; i < N; i++){ cin >> array[i]; }

    int ans = 0;
    int isOk = true;
    if (array.size() < 1){ ans = -1; }
    else if (array.size() >= 2) {
        for (int i = 2; i < N; i++){
            for (int d1 = -1; d1 <= 1; d1++){
                for (int d2 = -1; d2 <= 1; d2++){
                    // 공차를 9가지 경우의 수에 대해 체크
                    int a_prepre = (array[i - 2] + d1);
                    int a_pre = (array[i - 1] + d2);
                    int diff = (array[i - 1] + d2) - (array[i - 2] + d1);
                    if (array[i] - (array[i - 1] + d2) == diff){
                        ans += 0;
                    }
                    else if ((array[i] - 1) - (array[i - 1] + d2) == diff ){
                        ans += 1;
                    }
                    else if ((array[i] + 1) - (array[i - 1] + d2) == diff ){
                        ans += 1;
                    }
                    else{
                        isOk = false;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
/*
1차 시도: 등차 수열 가능여부
        -> arrSize == 1 -> return 0
        -> arrSize > 1
        --> next - pre = d
        --> a_n = a_0 + d * (n - 1)
        경우의수: 3가지 (+1, -1, 0)

*/