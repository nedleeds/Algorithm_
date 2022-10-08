#include <iostream>
#include <queue>
using namespace std;

int testCase;
int N, M, R, C, L;
int MAP[50][50];
int visited[50][50];
int dR[4] = { -1, 1, 0, 0 };
int dC[4] = { 0, 0,-1, 1 };
struct Node { int r, c; };
vector<int> dirs[7] = {
    {0, 1, 2, 3}, //╩С,го,аб,©Л
    {0, 1}, // ╩С,го
    {2, 3}, // аб,©Л
    {0, 3}, // ╩С,©Л
    {1, 3}, // го,©Л
    {1, 2}, // го,аб
    {0, 2}  // ╩С,аб
};

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            MAP[i][j] = 0;
            visited[i][j] = 0;
        }
}

bool checkDir(Node now, Node next, vector<int> nextDir) {
    for (int i = 0; i < nextDir.size(); i++) {
        Node check = { next.r + dR[nextDir[i]], next.c + dC[nextDir[i]] };
        if (check.r == now.r && check.c == now.c)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> testCase;
    for (int tc = 1; tc <= testCase; tc++) {
        int ans = 0;
        init();
        cin >> N >> M >> R >> C >> L;

        for (int r = 0; r < N; r++)
            for (int c = 0; c < M; c++)
                cin >> MAP[r][c];

        queue<Node> nodeQ;
        nodeQ.push({ R, C });
        visited[R][C] = 1;
        ans++;


        while (!nodeQ.empty()) {
            Node now = nodeQ.front();
            nodeQ.pop();

            vector<int> nowDir = dirs[MAP[now.r][now.c] - 1];
            for (int i = 0; i < nowDir.size(); i++) {
                Node next = { now.r + dR[nowDir[i]], now.c + dC[nowDir[i]] };
                vector<int> nextDir = dirs[MAP[next.r][next.c] - 1];
                if (!checkDir(now, next, nextDir))
                    continue;
                if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= M)
                    continue;
                if (MAP[next.r][next.c] == 0)
                    continue;
                if (visited[next.r][next.c] != 0)
                    continue;

                visited[next.r][next.c] = visited[now.r][now.c] + 1;
                if (visited[next.r][next.c] > L)
                    continue;
                ans++;
                nodeQ.push(next);
            }
        }


        cout << "#" << tc << " " << ans << '\n';
    }



    return 0;
}