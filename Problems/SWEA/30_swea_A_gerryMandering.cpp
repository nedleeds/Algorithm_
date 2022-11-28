#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int TestCase, N;
vector<vector<int>> NearInfo;
vector<int> Population;

int bfs(void *pGroup){
    // 인접 확인
    // 1. 현재 그룹에 속한 마을인가? (selected)
    // 2. 방문한 적이 없는 마을인가? (DAT)
    vector<int> group = *(vector<int> *)pGroup;
    bool selected[8] = {0};
    int DAT[8] = {0};
    int cnt = 0;
    int s = 0;

    for (auto a: group){
        selected[a] = true; // 현재 group 의 마을 표시
        s += Population[a]; // 현재 group 의 유권자 총 합
    }

    queue<int> q;
    q.push(group[0]);
    DAT[group[0]] = 1;
    while(!q.empty()){
        int now = q.front();
        cnt++;
        q.pop();

        for (int i = 0; i < NearInfo[now].size(); i++){
            int next = NearInfo[now][i];
            if (DAT[next]) continue; // 방문한 적 없는 곳?
            if (selected[next] == false) continue; // 현재 그룹 안에 있는 곳?
            DAT[next] = 1;
            q.push(next);
        }
    }

    // bfs 깊이 == 현재 그룹 수 
    if (cnt == group.size()){
        return s;
    }
    else{
        return -1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("../SampleInput/input.txt", "r", stdin);
    
    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        int ans = 2134567890;

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
        Population.resize(N);
        for (int i = 0; i < N; i++){
            cin >> Population[i];
        }

        // Binary Counting - 부분 집합 만들기 (총 원소 수 : N)
        // i: 부분 집합의 원소 개수 (1개 ~ N-1 개) -> N/2 - 1
        for (int i = 1; i < (1 << (N - 1)); i++){
            vector<int> A;
            vector<int> B;

            // 마을 그룹 짓기 - A or B
            for (int j = 0; j < N; j++){
                if (i & (1 << j)){
                    // if (j번째 bit가 1이면) - 그룹 A로
                    A.push_back(j);
                }
                else{
                    B.push_back(j);
                }
            }

            // A, B 그룹 둘 다 인접성 확보 시 최저 인구 갱신
            int numA = bfs(&A);
            int numB = bfs(&B);
            if ( numA != -1 && numB != -1){
                ans = min(ans, abs(numA - numB));
            }
        }

        cout << "#" << tc << " " << ans << '\n';

        for (int r = 0; r < N; r++){
            NearInfo[r].clear();
        }
        Population.clear();
    }

    return 0;
}