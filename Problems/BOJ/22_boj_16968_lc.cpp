#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    string cmd;
    cin >> cmd;

    int totalCnt = 1;
    char preCmd = '\0';
    for (char c:cmd){
        if (c == 'c'){
            totalCnt *= (c == preCmd) ? 25 : 26;
        }
        else{
            totalCnt *= (c == preCmd) ? 9 : 10;
        }
        preCmd = c;
    }

    cout << totalCnt << '\n';

    return 0;
}