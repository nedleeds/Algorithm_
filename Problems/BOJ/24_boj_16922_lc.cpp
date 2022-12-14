#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int N;
unordered_map<int, int> Chk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N;

    // a:I(1), b:V(5), c:X(10), d:L(50)
    for (int a = 0; a < N + 1; a++){
        for (int b = 0; b < N + 1; b++){
            for (int c = 0; c < N + 1; c++){
                int d = N - (a + b + c);
                int s = a + b * 5 + c * 10 + d * 50;
                if ((a + b + c < N + 1)){ Chk[s] += 1; }
            }
        }
    }

    cout << Chk.size() << '\n';

    return 0;
}
/*
서로 다른 수의 개수 
-> 다르다의 기준은 합이 달라야하는 것
-> XXXI 와 IXXX는 동일한 것으로 취급
*/