// 게리멘더링 - G4
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int TestCase, CntArea;
vector<int> People, Team;
unordered_map<int, vector<int>> NearInfo;
unordered_map<int, bool> DAT;

void reset(){
    People.clear();
    NearInfo.clear();
}

bool isAdjacent(){
    // 현재 Team 의 영역들간의 인접 판단
    // Area in Team 하나씩 체크
    for (int i = 0; i < Team.size() - 1; i++){
        int area = Team[i];
        int nearFlag = false;
        for (auto near : NearInfo[area]){
            if (near == Team[i + 1]) nearFlag = true;
        }
        if (nearFlag == false) return false; 
    }
    return true;
}

void dfs(int level){
    
    if (level == CntArea){
        for (auto t:Team){ cout << t; }
        cout << '\n';
        return ;
    }

    for (int i = level + 1; i <= CntArea; i++){
        if (DAT[i]) continue;
        DAT[i] = 1;
        Team.push_back(i);

        dfs(i);

        DAT[i] = 0;
        Team.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> CntArea;

        // set People
        People.resize(CntArea);
        for (int i = 0; i < CntArea; i++)
            cin >> People[i];

        // set Adjacent Area
        for (int area = 1; area < CntArea; area++){
            int cntNear;
            cin >> cntNear;
            for (int j = 0; j < cntNear; j++){
                int nearArea;
                cin >> nearArea;
                NearInfo[area].push_back(nearArea);
            }
        }
        

        dfs(0);
        
        reset();
    }

    return 0;
}
