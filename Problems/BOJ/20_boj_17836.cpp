#include <tuple>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int mat[100][100];
int dist[100][100][2];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

    freopen("../SampleInput/input.txt", "r", stdin);

	int n, m, t;
	cin >> n >> m >> t;
	
    // 맵 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
    // vst 초기화: -1
	memset(dist, -1, sizeof(dist));

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
            // 범위 체크
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (z == 0) { // sord 를 지나가기 전
				if (mat[tx][ty] == 0 && dist[tx][ty][z] == -1) {
                    // 맵에 길이 있는 곳 && 아직 방문 전
					dist[tx][ty][z] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, z));
				}
				else if (mat[tx][ty] == 2 && dist[tx][ty][z] == -1) {
                    // 검이 있는 곳 && 아직 방문 전
					dist[tx][ty][1] = dist[x][y][z] + 1; // z=1에 거리 업데이트
					q.push(make_tuple(tx, ty, 1));
				}
			}
			else { 
                // 검을 가지고 있는 경우 -> 벽이 있는 경우 + 방문 한적 없으면 + 1
				if ((mat[tx][ty] == 0 || mat[tx][ty] == 1) && dist[tx][ty][z] == -1) {
					dist[tx][ty][z] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, z));
				}
			}
		}
	}

	int ans = -1;
	if (ans == -1 || ans > dist[n - 1][m - 1][0]) {
		ans = dist[n - 1][m - 1][0];
	}
	if (ans == -1 || ans > dist[n - 1][m - 1][1]) {
		ans = dist[n - 1][m - 1][1];
	}

	if (ans >= 0 && ans <= t) {
		cout << ans << '\n';
	}
	else {
		cout << "Fail\n";
	}

	return 0;
}
// #include <iostream>
// #include <vector>
// #include <queue>
// #define INF 2134567890
// using namespace std;

// int N, M, T;
// int dR[4] = {-1, 1, 0, 0};
// int dC[4] = {0, 0, -1, 1};
// struct POS {int r, c; };
// vector<vector<int>> Map, Vst;

// void bfs(){
//     queue<POS> q;
//     Vst[0][0] = 0;
//     q.push({0, 0});

//     bool isSord = false;
//     while(!q.empty()){
//         POS now = q.front();
//         q.pop();

//         for (int i = 0; i < 4; i++){
//             POS next = {now.r + dR[i], now.c + dC[i]};
//             if (next.r < 0 || next.r >= N) continue;
//             if (next.c < 0 || next.c >= M) continue;
//             if (Map[next.r][next.c] == 1 && !isSord) continue;
//             if (Map[next.r][next.c] == 2) { isSord = true; }

//             if (Vst[next.r][next.c] > Vst[now.r][now.c] + 1){
//                 Vst[next.r][next.c] = Vst[now.r][now.c] + 1;
//                 q.push(next);
//             }
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(), cout.tie();

//     freopen("../SampleInput/input.txt", "r", stdin);

//     cin >> N >> M >> T;

//     Map.resize(N, vector<int>(M, 0));
//     Vst.resize(N, vector<int>(M, INF));
//     for (int r = 0; r < N; r++){
//         for (int c = 0; c < M; c++){
//             cin >> Map[r][c];
//         }
//     }

//     bfs();
//     int ans =  Vst[N - 1][M - 1];
//     if (0 <= ans && ans <= T) { cout << ans << '\n'; }
//     else{ cout << "Fail\n"; }

//     Map.clear();
//     Vst.clear();
//     return 0;
// }