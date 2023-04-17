#include <iostream>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N;
    int cnt = 0;
    while(N--)
    {
        int num = 0;
        bool isPrime = true;
        cin >> num;

        for (int i = 1; i < num; i++){
            if (1 < i && (num % i == 0)){
                isPrime = false;
                break;
            }
        }
        
        if (num == 2 || (1 < num && isPrime)){
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}