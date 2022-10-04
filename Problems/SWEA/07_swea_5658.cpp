#include <iostream>
#include <vector>
#define STEPSIZE 3
using namespace std;

int testCase, totalLength, K;
string numbers;

string getHexa(int start, int totalLength){
    string currHexa = "";
    for (int step=0; step<STEPSIZE; step++){
        int idx = (start+step)%totalLength;
        currHexa += numbers[idx];
    }
    return currHexa;
}

bool cmp(int a, int b){
    if (a < b) return true;
    if (a > b) return false;
    else return false;
}

int main()
{
    // char* a = "0xFF";
    // cout << "Hex: " << a << '\n';
    // cout << "Dec: " << (int)strtol(a, NULL, 16) << '\n';
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> testCase;
    for (int tc=1; tc<=testCase; tc++){
        // get the numbers
        cin >> totalLength >> K >> numbers;

        // set the indices for numbers with given STEPSIZE
        // set the hexValues
        vector<int>  hexValues;
        for (int i=0; i<totalLength; i++){
            // get the step indices
            string currHexString = getHexa(i, totalLength);
            int currHex = stoul(currHexString, NULL, 16);
             hexValues.push_back(currHex);
            // cout << "currHex: "<< currHexa << "\n";
        }   
        sort(hexValues.begin(), hexValues.end(), cmp);
        // cout << hexValues[K] << '\n';
        for (int i=0; i<totalLength; i++){
            cout << hexValues[i] << '\n';
        }
        printf("%d\n", hexValues[K]);
    }

    return 0;    
}
/*
1
12 10
1B3B3B81F75E
*/