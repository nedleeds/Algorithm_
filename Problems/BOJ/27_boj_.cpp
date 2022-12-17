#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> Values, KeyValues;
unordered_map<int, int> DAT;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int n;
    cin >> n;
    Values.resize(n, 0);
    for (int i = 0; i < n; i++){
        cin >> Values[i];
        KeyValues.push_back(Values[i]);
        DAT[Values[i]] += 1;
    }
    
    // 10 -> 1 2 3 4 [5 6 7 8 9] 10
    // 11 -> 1 2 3 4 [5 6 7 8 9 10] 11

    int cnt = 0;
    for (int v: Values){
        if (v > 2){
            if (v % 2){ // 홀수
                for (int i = v/2 + 1; i < v; i++){
                    if ((DAT[i] && DAT[v - i]) || (DAT[i] >= 2 && i * 2 == v)) {
                        cnt++;
                        break;
                    }
                }
            }
            else{ // 짝수
                for (int i = v/2; i < v; i++){
                    if ((DAT[i] && DAT[v - i]) || (DAT[i] >= 2 && i * 2 == v)) {
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    cout << cnt << '\n';
    Values.clear();
    return 0;
}