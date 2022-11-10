#include <iostream>
#include <queue>
#include <vector>
#define INF 2134567890
using namespace std;

struct POS {int row, col;};
struct BC {POS pos; int chrgArea, amount;};

int dR[5] = {0,-1, 0, 1, 0};
int dC[5] = {0, 0, 1, 0,-1};
int MAP[8][10][10];

int getDistance(POS a, POS b){
	return abs(a.row - b.row) + abs(a.col - b.col);
}

void bfs(int bcIdx, BC battery){
	int row = battery.pos.row;
	int col = battery.pos.col;
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = { 0, 0,-1, 1};
	int chargeArea = battery.chrgArea;

	queue<POS> q;
	MAP[bcIdx][row][col] = battery.amount;

	q.push({row, col});
	while(!q.empty()){
		POS now = q.front();
		q.pop();

		if (getDistance(now, {row, col}) >=  chargeArea) break ;
		
		for (int i=0; i<4; i++){
			POS next = {now.row + dr[i], now.col + dc[i]};
			if (next.row < 0 || next.col < 0) continue;
			if (next.row >= 10 || next.col >= 10) continue;	
			MAP[bcIdx][next.row][next.col] = battery.amount;
			q.push(next);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
freopen("../SampleInput/input.txt", "r", stdin);

	int testCase;
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++){
		int numMove, numBC;
		cin >> numMove >> numBC;
		// set Move Dirs
		vector<int> directions[2];
		for (int j = 0; j < 2; j++){
			directions[j].clear();
			directions[j].push_back(0);
			for (int i = 0; i < numMove; i++){
				int dir;
				cin >> dir;
				directions[j].push_back(dir);
			}
		}
				
		// set Battery Charger
		vector<BC> batteryV;
		for (int i = 0; i < numBC; i++){
			BC bc;
			cin >> bc.pos.col >> bc.pos.row;
			cin >> bc.chrgArea >> bc.amount;
			bc.pos.col -= 1;
			bc.pos.row -= 1;
			batteryV.push_back(bc);
			bfs(i, bc); // bfs for set charge area
		}
		// move !
		POS nowA = {0, 0};
		POS nowB = {9, 9};
		int chargeSum = 0;
		for (int t = 0; t < directions[0].size(); t++){
			// get idx of Direction & check next position
			int dirA = directions[0][t];
			int dirB = directions[1][t];
			POS nextA = {nowA.row + dR[dirA], nowA.col + dC[dirA]};
			POS nextB = {nowB.row + dR[dirB], nowB.col + dC[dirB]};	
			// check amount of MAP(battery Amounts in area) from bfs()
			int maxAmount = -INF;
			for (int i = 0; i < numBC; i++){
				int amountA = MAP[i][nextA.row][nextB.col];
				for (int j = 0; j < numBC; j++){
					int amountB = MAP[j][nextB.row][nextB.col];
					if (i == j){
						amountA /= 2;
						amountB /= 2;
					}
					maxAmount = max(maxAmount, amountA + amountB);
				}
			}
			chargeSum += maxAmount;
			// update position before move
			nowA = nextA;
			nowB = nextB;
		}
		cout << "#" << tc << " " << chargeSum << '\n';
		directions[0].clear();
		directions[1].clear();

		for (int i = 0; i < numBC; i++)
			for (int r = 0; r < 10; r++)
				for (int c = 0; c < 10; c++)
					MAP[i][r][c] = 0;
	}
	return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <vector>

// using namespace std;

// struct user{
//     int y, x;
// };
// struct beacon{
//     int y,x;
//     int d,p,u;
// };
// user usr[2];
// beacon bc[8];
// vector <int> moving[2];
// int T,M,A,res;
// int dy[]={0,-1,0,1,0};
// int dx[]={0,0,1,0,-1};
// int ret=0;

// bool check(int a, int b){
//     int dist = abs(usr[a].x - bc[b].x) + abs(usr[a].y - bc[b].y);
//     if(dist <= bc[b].d){
//         return true;
//     }else{
//         return false;
//     }
// }

// void dfs(int user, int d){
//     if(user==2){
//         ret = max(ret,d);
//         return;
//     }
//     for(int i=0;i<A;i++){
//         if(bc[i].u==0&&check(user,i)){
//             bc[i].u=1;
//             dfs(user+1,d+bc[i].p);
//             bc[i].u=0;
//         }
//     }
//     dfs(user+1,d);
// }


// int count(){
//     ret = 0;
//     dfs(0,0);
//     return ret;
// }

// void solve(){
//     moving[0].clear();
//     moving[1].clear();

//     for(int i=0;i<A;i++)
//         bc[i].u=0;

//     usr[0].x=1, usr[0].y=1;
//	   usr[1].x=10,usr[1].y=10;
    
//     cin >> M >> A;
//     for(int i = 0; i < 2; i++)
//         for(int j = 0;j < M; j++){
//             int a;
//             cin >> a;
//             moving[i].push_back(a);
//         }

//     for(int i = 0; i < A; i++)
//         cin >> bc[i].x >> bc[i].y >> bc[i].d >> bc[i].p;

//     res += count();

//     for(int i=0;i<M;i++){
//         for(int j=0;j<2;j++){
//             usr[j].x += dx[moving[j][i]];
//             usr[j].y += dy[moving[j][i]];
//         }
//         res+=count();
//     }
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie();
// 	cout.tie();

//     freopen("../SampleInput/input.txt","r",stdin);
//     cin>>T;

//     for(int i=1;i<=T;i++){
//         res=0;
//         solve();
//         cout<<"#"<<i<<" "<<res<<"\n";
//     }

//     return 0;
// }
