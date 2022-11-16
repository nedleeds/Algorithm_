#include <iostream>
#include <queue>
using namespace std;

int N, TestCase, M, K;
int Map[100][100];
int Tmp[100][100];
int Dir[100][100];
int dR[5] = {0, -1, 1, 0, 0};
int dC[5] = {0, 0, 0, -1, 1};
struct BUG{ int r, c, cnt, dir;} Bug;

bool operator < (BUG a, BUG b){
	if (a.cnt < b.cnt) return true;
	if (a.cnt > b.cnt) return false;
	return false;
}
priority_queue<BUG> Pq; 

void move(){

	// move the bug one by one but simultaneously
	while(!Pq.empty()){
		BUG now = Pq.top();
		Pq.pop();

		int nr = now.r + dR[now.dir];
		int nc = now.c + dC[now.dir];

		// range check
		if (nr < 0 || nr >= N) continue;
		if (nc < 0 || nc >= N) continue;

		// update dirrection
		if (Tmp[nr][nc] == 0){
			Dir[nr][nc] = now.dir;
			// Dir[nr][nc] = Dir[now.r][now.c];
		}
		
		// update amount 
		Tmp[nr][nc] += Map[now.r][now.c];
		Map[now.r][now.c] = 0;

		// edge condition
		if (nr == 0 || nr == N-1 || nc == 0 || nc == N-1){
			Tmp[nr][nc] /= 2;
			
			if 		(Dir[nr][nc] == 1){ Dir[nr][nc] = 2; }
			else if (Dir[nr][nc] == 2){ Dir[nr][nc] = 1; }
			else if (Dir[nr][nc] == 3){ Dir[nr][nc] = 4; }
			else if (Dir[nr][nc] == 4){ Dir[nr][nc] = 3; }
		}

	}

	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++){
			Map[r][c] = Tmp[r][c];
			Tmp[r][c] = 0;

			if (Map[r][c]){ Pq.push({r, c, Map[r][c], Dir[r][c]}); }
		}
	}
	int de = 1; 
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("../SampleInput/input.txt", "r", stdin);

	cin >> TestCase;
	for (int tc = 1; tc <= TestCase; tc++){
		cin >> N >> M >> K;

		// set Bugs with priority_Q based on Count - bigger first
		for (int i = 0; i < K; i++){
			cin >> Bug.r >> Bug.c >> Bug.cnt >> Bug.dir;
			Map[Bug.r][Bug.c] = Bug.cnt;
			Dir[Bug.r][Bug.c] = Bug.dir;
			Pq.push(Bug);
		}

		// move for the M times
		for (int t = 0; t < M; t++){ move(); }

		// compute total bugs' cnt in the Map
		int s = 0;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				s += Map[r][c];

		cout << "#" << tc << " " << s << '\n';

		for (int r = 0; r < N; r++){
			for (int c = 0; c < N; c++){
				Map[r][c] = 0;
				Dir[r][c] = 0;
				while(!Pq.empty()){ Pq.pop(); }
			}
		}
	}
	return 0;
}