#include <iostream>
#include <math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int a, b;
    cin >> a >> b;

    int midA = (int) sqrt(a);
    int midB = (int) sqrt(b);

    int minVal = 0;
    int maxVal = 0;

    for (int x = a - 1 ; x > 1; x--){
        if (a % x == 0){
            for (int y = b - 1; y > 1; y--){
                if (b % y == 0 && x == y){
                    maxVal = y;
                    break;
                }
            }
            if (maxVal != 0) {
                break;
            }
        }
    }
    cout << maxVal << ' ';

    for (int i = a; i < )
    cout << minVal << '\n';

    return 0;
}