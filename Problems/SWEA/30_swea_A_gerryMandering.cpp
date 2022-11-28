#include <iostream>
#include <vector>
using namespace std;

int TestCase, N;
vector<vector<int>> NearInfo;
vector<int> Cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("../SampleInput/input.txt", "r", stdin);
    
    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> N;

        // 인접리스트 만들기 - 마을 index: 0 ~ 7
        NearInfo.resize(N);
        for (int r = 0; r < N; r++){
            for (int c = 0; c < N; c++){
                int isNear;
                cin >> isNear;
                if (isNear){
                    NearInfo[r].push_back(c);
                }
            }
        }

        // 인구수 입력 받기
        Cnt.resize(N);
        for (int i = 0; i < N; i++){
            cin >> Cnt[i];
        }

        // Binary Counting - 부분 집합 만들기
        for (int i = 0; i < (1 << N); i++){
            vector<int> A;
            vector<int> B;
            for (int j = 0; j < N; j++){
                // j번째 비트 확인
                if (i && (1 << j)){
                    A.push_back(j);
                }
                else{
                    B.push_back(j);
                }
            }
        }


    }

    return 0;
}