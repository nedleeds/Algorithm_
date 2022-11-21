#include <iostream>
#include <vector>
#define INF 213457890
using namespace std;

int TestCase, TotalShootCnt, Gap;
int ShootApeach[11];
int ShootRyan[11];
vector<int> Ans;

void setScore(){
    int ScoreApeach = 0;
    int ScoreRyan = 0;
    for (int i = 0; i < 11; i++){
        if (ShootApeach[i] == ShootRyan[i] && ShootRyan[i] == 0)
            continue;
        if (ShootApeach[i] >= ShootRyan[i]) 
            ScoreApeach += 10 - i;
        else 
            ScoreRyan += 10 - i;
    }
    int de = 1;

    if (ScoreRyan > ScoreApeach){
        if (Gap < ScoreRyan - ScoreApeach){
            Gap = ScoreRyan - ScoreApeach;

            for (int j = 0; j < 11; j++)
                Ans[j] = ShootRyan[j];
            
            int cntRyan = 0;
            for (auto cnt: ShootRyan){ 
                cntRyan += cnt; 
            }
            if (cntRyan < TotalShootCnt){
                Ans[10] = TotalShootCnt - cntRyan;
            }
        }
        else if (Gap == ScoreRyan - ScoreApeach){
            for (int j = 10; j >= 0; j--){
                if (ShootRyan[j] != 0 && Ans[j] == 0){
                    for (int k = 0; k < 10; k++)
                        Ans[k] = ShootRyan[k];
                    
                    int cntRyan = 0;
                    for (auto cnt: ShootRyan){ 
                        cntRyan += cnt; 
                    }
                    if (cntRyan < TotalShootCnt){
                        Ans[10] = TotalShootCnt - cntRyan;
                    }
                    return ;
                }
            }
        }
    }
    int de1 = 1;
}

void dfs(int target, int shootCnt){
    if (shootCnt > TotalShootCnt) { return; }
    if (target == 11){
        setScore();
        return ;
    }

    // Ryan 격발 수 = Apeach 격발 수 + 1
    ShootRyan[target] = ShootApeach[target] + 1;
    dfs(target + 1, shootCnt + ShootRyan[target]);

    // Ryan 격발 수 = 0 
    ShootRyan[target] = 0;
    dfs(target + 1, shootCnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> TotalShootCnt;
        Gap = -INF;
        Ans.resize(11);
        
        for (int i = 0; i < 11; i++)
            cin >> ShootApeach[i];

        dfs(0, 0);
        
        int s = 0;
        for (int i = 0; i < 11; i++) 
            s += Ans[i]; 

        if (s == 0){
            cout << "-1" <<'\n';
        }
        else{
            for (int i = 0; i < 11; i++){
                cout << Ans[i] << ' ';
                Ans[i] = 0;
                ShootRyan[i] = 0;
            }
            cout << '\n';
        }
    }

    return 0;
}

/*
ans
[0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0]
[-1]
[1, 1, 2, 0, 1, 2, 2, 0, 0, 0, 0]
[1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2]
*/