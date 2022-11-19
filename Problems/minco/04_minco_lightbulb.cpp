#include <iostream>
#include <vector>
#include <unordered_map>
#define INF 2134567890
using namespace std;

int NumLight, NumButton, NumConnect, Ans; 
vector<int> Lights, Clicked;
vector<int> ButtonCnts;
unordered_map<int, vector<int>> ButtonHash;

void clickBtn(int btnIdx){
    // toggle lights which is connected to Light[btnIdx]
    for (auto idx: ButtonHash[btnIdx])
        Lights[idx] = Lights[idx] ? 0 : 1;
}

int countLight(){
    int s = 0;
    for (auto cnt: Lights){ s += cnt; }
    return s;
}

void dfs(int btnIdx, int clickNum){
    // finish condition
    if (clickNum == NumButton * 2)
        return ;

    // count lights on
    if (countLight() == NumLight){
        Ans = min(Ans, clickNum);
        return ;
    }

    for (int nextBtn = 0; nextBtn < NumButton; nextBtn++){
        if (ButtonCnts[nextBtn] > 2) continue;
        clickBtn(nextBtn);
        ButtonCnts[nextBtn]++;

        dfs(btnIdx + 1, clickNum + 1);
        
        clickBtn(nextBtn);
        ButtonCnts[nextBtn]--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> NumLight >> NumButton >> NumConnect;
    Lights.resize(NumLight);
    ButtonCnts.resize(NumButton);
    Ans = INF;

    // set Lights
    for (int i = 0; i < Lights.size(); i++)
        cin >> Lights[i];

    int num = 0;
    for (int j = 0; j < NumButton; j++)
        for (int k = 0; k < NumConnect; k++){
            cin >> num;
            ButtonHash[j].push_back(num - 1);
        }

    dfs(0, 0);

    cout << Ans << '\n';

    return 0;
}