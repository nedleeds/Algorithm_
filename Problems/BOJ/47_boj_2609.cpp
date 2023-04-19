#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int a, b;
    cin >> a >> b;

    int maxVal = 0;
    int minNum = min(a, b);
    int maxNum = max(a, b);

    for (int i = maxNum; i > 0; i--){
        if (maxNum % i == 0){
            for (int j = minNum; j > 0; j--){
                if (minNum % j == 0 && i == j){
                    maxVal = i;
                    break;
                }
            }
        }
        if (maxVal != 0) break;
    }

    if (maxVal != 0){
        cout << maxVal << '\n';
        cout << a * b / maxVal << '\n';
    }
    else {
        cout << 1 << '\n';
        cout << a * b << '\n';
    }

    return 0;
}