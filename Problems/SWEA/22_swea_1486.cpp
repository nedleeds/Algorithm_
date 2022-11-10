#include <iostream>
#include <vector>
#define INF 213467890
using namespace std;

vector<int> heights;
int ans = INF;
int b;

void dfs(int idx, int height){
    if (idx == heights.size()){
        if (height >= b) ans = min(ans, height);
        return;
    }

    // 다음 인덱스, 높이 선택 o - 높이 업데이트
    dfs( idx + 1, height + heights[idx] );
    // 다음 인덱스, 높이 선택 x
    dfs( idx + 1, height);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int testCase, n;
	cin >> testCase;
    
    for (int tc = 1; tc <= testCase; tc++){
        cin >> n >> b;

        for (int i = 0; i < n ; i++){
            int h;
            cin >> h;
            heights.push_back(h);
        }
        dfs(0, 0);
        cout << "#" << tc << " " << ans - b << '\n';

        // 값 초기화
        heights.clear();
        ans = INF;
    }
    return 0;
}

/*
2가지 경우로 나눠 탐색을 진행한다
- 직원을 탑으로 사용하는 경우
- 직원을 탑으로 사용하지 않는 경우
*/