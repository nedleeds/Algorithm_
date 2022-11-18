#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int TestCase, N, M, L, Ans;
int Map[50][50];
int Vst[50][50];
struct POS {int r, c;} Start;

// pipe1: 상, 하, 좌, 우
vector<vector<POS>> Pipes = {
    // pipe1
    {   {0, -1},   // 좌
        {-1, 0},   // 상
        {0, 1},    // 우
        {1, 0}  }, // 하 

    // pipe2
    {   {-1, 0},   // 상
        {1, 0}  }, // 하

    // pipe3
    {   {0, -1},   // 좌
        {0, 1}  }, // 우
    
    // pipe4: 상, 우
    {   {-1, 0},   // 상
        {0, 1}  }, // 우

    // pipe5: 우, 하
    {   {0, 1},    // 우
        {1, 0}  }, // 하

    // pipe6: 좌, 하
    {   {0, -1},   // 좌
        {1, 0}  }, // 하
    
    // pipe7: 상, 좌
    {   {-1, 0},   // 상
        {0, -1} }  // 좌
}; 

void reset(){
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++){
            Map[r][c] = 0;
            Vst[r][c] = 0;
        }
    Ans = 0;
}

bool checkPipe(POS now, POS next){
    vector<POS> nextPipe = Pipes[Map[next.r][next.c] - 1];
    
    // next 의 next 방향들 중에 
    // Now 가 있으면 return true 없으면 false
    for (int i = 0; i < nextPipe.size(); i++){
        POS nextNext;
        nextNext.r = next.r + nextPipe[i].r;
        nextNext.c = next.c + nextPipe[i].c;
        if (nextNext.r < 0 || nextNext.r >= N) continue;
        if (nextNext.c < 0 || nextNext.c >= M) continue;
        if (nextNext.r == now.r && nextNext.c == now.c)
            return true;
    }
    return false;
}

void bfs(POS start){
    queue<POS> q;
    q.push(start);

    Vst[start.r][start.c] = 1;
    while(!q.empty()){
        POS now = q.front();
        q.pop();
        if (Vst[now.r][now.c] > L) continue;
        Ans++;
        vector<POS> d = Pipes[Map[now.r][now.c] - 1];
        for (int i = 0; i < d.size(); i++){
            POS next = {now.r + d[i].r, now.c + d[i].c};

            if (next.r < 0 || next.r >= N)  continue;
            if (next.c < 0 || next.c >= M)  continue;
            if (Map[next.r][next.c] == 0)   continue;
            if (Vst[next.r][next.c])        continue;
            if (!checkPipe(now, next))      continue;

            if (Vst[now.r][now.c] <= L - 1){
                Vst[next.r][next.c] = Vst[now.r][now.c] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> N >> M >> Start.r >> Start.c >> L;

        // set Map
        for (int row = 0; row < N; row++){
            for (int col = 0; col < M; col++){
                cin >> Map[row][col];
            }
        }

        bfs(Start);

        cout << "#" << tc << " " << Ans << '\n';

        // reset the global variable
        reset();
    }


    return 0;
}