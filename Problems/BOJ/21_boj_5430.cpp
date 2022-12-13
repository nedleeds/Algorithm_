#include <iostream>
#include <vector>
using namespace std;

int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> T;
    string cmd;
    for (int i = 0; i <= T; i++){
        cin >> cmd;

        int arrSize;
        cin >> arrSize;

        string arrS;
        cin >> arrS;

        vector<int> arr, tmp;
        string tmpNum;
        
        if (arrS.size() > 2){ 
            for (auto c:arrS){ 
                if (c == ','){
                    arr.push_back(stoi(tmpNum));
                    tmpNum.clear();
                }
                else if ((c != '[') and (c != ']')){
                    tmpNum += c;
                }
                else if (c == ']'){
                    arr.push_back(stoi(tmpNum));
                    tmpNum.clear();
                }
            }
        }

        bool isError = true;
        if (arr.size() > 0) {
            isError = false;
            for (char c:cmd){
                int currArrSize = arr.size();
                if (c == 'R'){
                    for (int k = 0; k < currArrSize; k++){
                        int back = arr.back();
                        arr.pop_back();
                        tmp.push_back(back);
                    }
                }
                else if (c == 'D'){
                    if (arr.size() == 0){
                        isError = true;
                        break;
                    }
                    else{
                        for (int k = 1; k < currArrSize; k++){
                            tmp.push_back(arr[k]);
                        }
                        for (int k = 0; k < currArrSize; k++){
                            arr.pop_back();
                        }
                    }
                }

                int tmpSize = tmp.size();
                for (int j = 0; j < tmpSize; j++){
                    arr.push_back(tmp[j]);
                }
                tmp.clear();
                int de = 1;
            }
        }
        
        if (!isError){
            cout << '[';
            for (int i = 0; i < arr.size(); i++){
                cout << arr[i];
                if (i < arr.size() - 1){
                    cout << ',';
                }
            }
            cout << "]\n";
        }
        else{
            cout << "error\n";
        }

        arr.clear();
        tmp.clear();
    }


    return 0;
}