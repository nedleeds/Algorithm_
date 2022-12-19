#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> Values;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int n;
    cin >> n;
    Values.resize(n, 0);
    for (int i = 0; i < n; i++){
        cin >> Values[i];
    }
    sort(Values.begin(), Values.end());

    int cnt = 0;
    for (int i = 0; i < n; i++){
        vector<int> checkV;
        for (int j = 0; j < n; j++){
            if (i != j) { checkV.push_back(Values[j]); }
        }

        int l = 0;
        int r = checkV.size() - 1;
        while( l < r ){
            if (checkV[l] + checkV[r] == Values[i]){
                cout << checkV[l] << " + " << checkV[r] << " = " << Values[i] <<'\n';
                cnt++;
                break;
            }

            else if (checkV[l] + checkV[r] < Values[i]){
                l++;
            }
            else {
                r--;
            }
        }

    }

    cout << cnt << '\n';
    Values.clear();
    return 0;
}