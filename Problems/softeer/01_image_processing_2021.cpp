// [21년 재직자 대회 예선] 이미지 프로세싱 - dfs 난이도 하
#include<iostream>
#include<vector>
using namespace std;

int MAP[130][130];
int visited[130][130];
int H, W;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = { 0, 0,-1, 1};
struct Node{
	int r, c;
};
int selectedColor, newColor;

void initVisited(){
	for (int r=0; r<130; r++)
		for (int c=0; c<130; c++)
			visited[r][c] = 0;
}

void printM(int m[130][130]){
	for (int i=1; i<=H; i++){
		for (int j=1; j<=W; j++)
			cout << m[i][j] << ' ';
		cout << '\n';
	}
}

void dfs(Node now){
	MAP[now.r][now.c] = newColor;

	for (int i=0; i<4; i++){
		Node next = {now.r + dR[i], now.c + dC[i]};
		int nr = next.r;
		int nc = next.c;
		if (nr<=0 || nc <=0 || nr > H || nc > W)
			continue;
		if (MAP[nr][nc] != selectedColor)
			continue;
		if (visited[nr][nc] != 0)
			continue;
		
		visited[nr][nc] = 1;
		dfs(next);
	}

}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	
	cin >> H >> W;
	for (int r=1; r<=H; r++)
		for (int c=1; c<=W; c++)
			cin >> MAP[r][c];
	
	int cmdCnt;
	cin >> cmdCnt;
	for (int c=0; c<cmdCnt; c++){
		int row, col;
		cin >> row >> col >> newColor;
		selectedColor = MAP[row][col];
		visited[row][col] = 1;
		dfs({row, col});
		initVisited();
	}

	printM(MAP);
	return 0;
}