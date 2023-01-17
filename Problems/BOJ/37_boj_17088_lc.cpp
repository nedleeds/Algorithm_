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

    int ans = 2e9;
    int isOk = false;
    if (array.size() == 0){
        ans = -1;
    }
    else if (array.size() <= 2){
        ans = 0;
    }
    else{
        for (int d1 = -1; d1 <= 1; d1++){
            for (int d2 = -1; d2 <= 1; d2++){

                int cnt = 0;
                int a0 = array[0] + d2;
                int diff = (array[1] + d1) - a0;
                if (d1 != 0) { cnt ++; }
                if (d2 != 0) { cnt ++; }

                isOk = true;
                for (int i = 2; i < N; i++){
                    int aN = diff * i + a0;
                    if (array[i] == aN){ cnt+= 0; }
                    else if (array[i] - 1 == aN) { cnt++; }
                    else if (array[i] + 1 == aN) { cnt++; }
                    else{
                        isOk = false;
                        break;
                    }
                }
                if (isOk && ans > cnt){ ans = cnt; }
            }
        }
    }

    if (ans == 2e9){ ans = -1; }
    cout << ans << '\n';

    return 0;
}
/*
1차 시도: 등차 수열 가능여부
        -> arrSize == 1 -> return 0
        -> arrSize > 1
        --> next - pre = d
        --> a_n = a_0 + d * (n - 1)
        ----> n - 1 : index 가 0부터 시작이므로, d * i 로 진행
        경우의수: 3가지 (+1, -1, 0)

*/