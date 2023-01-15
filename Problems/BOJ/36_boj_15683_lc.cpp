#include <iostream>
#include <vector>
using namespace std;

int MaxRow, MaxCol;
int Ans = 2e9;
int dR[4] = { 0, 1, 0, -1 };
int dC[4] = { 1, 0, -1, 0 };
struct Pos{ int r, c; };

vector<vector<int>> Map;
vector<Pos> CCTVs;

void check(vector<vector<int>> *tmp, Pos cctv, int dirIdx, int rotIdx){
    for (int i = 1; i < max(MaxRow, MaxCol); i++){
        int r = cctv.r + (dR[(dirIdx + rotIdx) % 4]) * i;
        int c = cctv.c + (dC[(dirIdx + rotIdx) % 4]) * i;
        if ( 0 <= r && r < MaxRow && 0 <= c && c < MaxCol){
            if ((*tmp)[r][c] == 6){ break; }
            if ((*tmp)[r][c] == 0){ (*tmp)[r][c] = 9; }
        }
    }
}

void dfs(int lvl, vector<int>* pRotates){
    if (lvl == CCTVs.size()){
        vector<vector<int>> temp(Map);
        for (int j = 0; j < CCTVs.size(); j++){
            int cctvDir = temp[CCTVs[j].r][CCTVs[j].c];
            int rotIdx = (*pRotates)[j];
            if (cctvDir == 1){
                check(&temp, CCTVs[j], 0, rotIdx);
            }
            else if (cctvDir == 2){
                check(&temp, CCTVs[j], 0, rotIdx);
                check(&temp, CCTVs[j], 2, rotIdx);
            }
            else if (cctvDir == 3){
                check(&temp, CCTVs[j], 0, rotIdx);
                check(&temp, CCTVs[j], 3, rotIdx);
            }
            else if (cctvDir == 4){
                check(&temp, CCTVs[j], 0, rotIdx);
                check(&temp, CCTVs[j], 2, rotIdx);
                check(&temp, CCTVs[j], 3, rotIdx);
            }
            else if (cctvDir == 5){
                check(&temp, CCTVs[j], 0, rotIdx);
                check(&temp, CCTVs[j], 1, rotIdx);
                check(&temp, CCTVs[j], 2, rotIdx);
                check(&temp, CCTVs[j], 3, rotIdx);
            }
        }

        int s = 0;
        for (int r = 0; r < MaxRow; r++){
            for (int c = 0; c < MaxCol; c++){
                if (temp[r][c] == 0){ s += 1; }
            }
        }
        if (s < Ans){ Ans = s; } 
        return ;
    }

    for (int i = 0; i < 4; i++){
        pRotates->push_back(i);
        dfs(lvl + 1, pRotates);
        pRotates->pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> MaxRow >> MaxCol;
    Map.resize(MaxRow, vector<int>(MaxCol));
    for (int r = 0; r < MaxRow; r++){
        for (int c = 0; c < MaxCol; c++){
            cin >> Map[r][c];
            if (1 <= Map[r][c] && Map[r][c] <= 5){
                CCTVs.push_back({r, c});
            }
        }
    }
    vector<int> rotates;
    dfs(0, &rotates);

    cout << Ans << '\n';

    Map.clear();
    CCTVs.clear();
    return 0;
}
/*
1차 시도 : Map 상의 CCTV 위치를 vector에 저장
         CCTV 종류는 총 5가지
         90도 회전 가능 -> 4번 돌려서 360도 돌게 만들어
         모든 CCTV에 대해서 회전 설정(0~3)
         if (lvl == CCTV.size()): 모든 cctv의 회전 상태 정립
         -> CCTV vector의 cctv를 하나씩 체크
         --> Map -> temp 복사
         --> temp[CCTV.r][CCTV.c] == 1 ~ 5
         ---> 1:dir[0] / 2:{dir[0],dir[1]} 
         --> Check(CCTV.r, CCTV.c, dir[idx]): 출발점 + 방향에 # 전환
         -> #이 아닌 0 인 수 체크
         -> 0 인 수가 Ans 보다 크면 업데이트
*/