#include <iostream>
#include <vector>
using namespace std;

int RowMax, ColMax;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};
struct CROSS { int r, c, l; };
vector<CROSS> Ans;
vector<string> Map;
vector<vector<bool>> Vst;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> RowMax >> ColMax;
    Map.resize(RowMax);
    for (int r = 0; r < RowMax; r++){
        cin >> Map[r];
    }

    Vst.resize(RowMax, vector<bool>(ColMax, false));
    for (int r = 0 ; r < RowMax; r++){
        for (int c = 0; c < ColMax; c++){
            if (Map[r][c]=='*'){
                int l = 1;
                while (true){
                    if (0 <= r - l && r + l < RowMax && 0 <= c - l && c + l < ColMax){
                        if (Map[r - l][c] == '*' && Map[r + l][c]  == '*' && Map[r][c - l] == '*' && Map[r][c + l] == '*'){ 
                            l++; 
                        }
                        else{
                            l -= 1;
                            break;
                        }
                    }
                    else{
                        l -= 1;
                        break;
                    }
                }
                if (l > 0){
                    Vst[r][c] = true;
                    for (int i = l; i > 0; i--){
                        Vst[r + i][c] = true;
                        Vst[r - i][c] = true;
                        Vst[r][c + i] = true;
                        Vst[r][c - i] = true;
                        Ans.push_back({r + 1, c + 1, i});
                    }
                }
                else{
                    continue;
                }
            }
        }
    }

    bool isFull = true;
    for (int r = 0; r < RowMax; r++){
        for (int c = 0; c < ColMax; c++){
            if (Map[r][c] == '*' && !Vst[r][c]){
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << Ans.size() << '\n';
    for (auto x:Ans){
        cout << x.r << " " << x.c << " " << x.l << '\n';
    }

    Map.clear();
    return 0;
}
/*
이번에 계속 정답이 틀리게 나온 이유:
1. 마지막 -1 을 출력하는 조건을 정확하게 이해를 못함
    -> Map 에 *이 있는데 방문하지 않은 경우만 -1 리턴하면 된다
    -> 나머지 경우는 *이 있는 곳은 모두 방문했으므로 정답 출력
2. 4가지 방향 배열에 대해서 틀에 갇힌 사고로 접근하지 말자
    -> 4방향을 한번에 체킹하면 된다
    -> 따라서, 길이를 늘리고 난 다음에(4방향 체크 후), Ans 에 push_back() 진행
3. 차분하게, 문제를 볼 때는 보다 많은 경우를 떠올리면서 접근하자
*/