#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct POS{int r, c;} Sticker;
vector<POS> Stickers;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/Input.txt", "r", stdin);

    int h, w, n;
    cin >> h >> w >> n;


    for (int i = 0; i < n; i++){
        cin >> Sticker.r >> Sticker.c;
        Stickers.push_back(Sticker);
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        int r1 = Stickers[i].r;
        int c1 = Stickers[i].c;
        for (int j = 0; j < n && i != j; j++){
            int r2 = Stickers[j].r; 
            int c2 = Stickers[j].c;
            for (int rot1 = 0; rot1 < 2; rot1++){
                for (int rot2 = 0; rot2 < 2; rot2++){
                    // 아래쪽으로 붙이기: r1 + r2
                    if (r1 + r2 <= h && max(c1, c2) <= w){
                        ans = max(ans, r1 * c1 + r2 * c2);
                    }
                    // 옆으로 붙이기: c1 + c2
                    if (max(r1, r2) <= h && c1 + c2 <= w){
                        ans = max(ans, r1 * c1 + r2 * c2);
                    }
                    swap(r2, c2);
                }
                swap(r1, c1);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
/* 
1차시도: 그저 또 또 dfs로 생각만 함
결국 해설 확인

2차시도: 구현 과정에서 r,c 입력이 인덱스로 착각함
       -> '크기' -> if 문안의 범위에 등호 기호 추가
       -> 정답 처리됨
*/