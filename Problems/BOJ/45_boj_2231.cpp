#include <iostream>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N;

    int checkNum = 0;
    while(checkNum <= N){
        // 자리수 체크
        int ten = 1;
        int pre = 0;
        int x = 0;
        while ( checkNum / ten >= 1){
            ten *= 10;
            x += (checkNum % ten - (pre)) / (ten / 10);
            pre = checkNum % ten;
        }

        if (checkNum + x == N){
            cout << checkNum << '\n';
            return 0;
        }
        checkNum++;
    }
    cout << 0 << '\n';
    return 0;
}