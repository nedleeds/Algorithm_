#include <iostream>
#include <vector>
using namespace std;

int testCase;
int mapSize, K, dist;
int MAP[10][10];
int visited[10][10];
int maxHeight = -2134567890;
struct Node{ int r, c; } N;
vector<Node> maxNodes;
int dR[4] = {-1, 1, 0, 0};
int dC[4] = { 0, 0,-1, 1};

void printMap(int M[10][10]);
void setMap();
void setMaxNodes(Node n);
void printMaxNodes();
void initVisited();
void dfs(Node now, int isDig, int step);
int findRoad();
/*
1
5 1       
9 3 2 3 2 
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> testCase;
	cin >> mapSize >> K;

	for (int tc=0; tc<testCase; tc++){
		int ans;
		setMap();
		printMap(MAP);
		ans = findRoad();
		cout << "#" << tc + 1 << " " << ans << '\n';
	}

	return 0;
}

void printMap(int M[10][10]){
	for (int row=0; row<10; row++){
		for (int col=0; col<10; col++)
			cout << M[row][col] << ' ';
		cout << "\n";	
	}
}

void setMap(){
	int maxHeight = -2134567890;
	int preMax = maxHeight; 
	for (int row=1; row<=mapSize; row++){
		for (int col=1; col<=mapSize; col++){
			cin >> MAP[row][col];
			setMaxNodes( (Node){row, col} );
			findRoad();
		}
	}
	printMaxNodes();
}

void setMaxNodes(Node n){
    if (maxHeight < MAP[n.r][n.c]){
        maxHeight = MAP[n.r][n.c];
        while(!maxNodes.empty()){ maxNodes.pop_back(); }
        maxNodes.push_back(n);
    }
    else if (maxHeight == MAP[n.r][n.c]){
        maxNodes.push_back(n);
    }
}

void printMaxNodes(){
	cout << "maxHeight: " << maxHeight << "\nmaxNodes: ";
    for (int i=0; i<maxNodes.size(); i++){
        cout << "(" << maxNodes[i].r <<", " << maxNodes[i].c << ") ";
    }
	cout << '\n';
}

int findRoad(){
	Node longestNode = {0, 0};
	int longest = -213456789;
	while(!maxNodes.empty()){
		Node startNode = maxNodes.back();
		maxNodes.pop_back();
		initVisited();
		visited[startNode.r][startNode.c] = 1;
		dfs(startNode, 0, 0);

		if (longest < dist){
			longest = dist;
		}
		printMap(visited);
		cout << "(" << startNode.r <<", "<< startNode.c << ") -> " << dist << '\n';
		dist = 0;
	}
	return longest;
}

void initVisited(){
	for (int row=0; row<mapSize; row++)
		for (int col=0; col<mapSize; col++)
			visited[row][col] = 0;
}

void dfs(Node now, int isDig, int step){
	dist = (int) max(dist, step);

	for (int i = 0; i < 4; i++){
		Node next = { now.r + dR[i], now.c + dC[i] };
		if (next.r < 1 || next.c < 1 || next.r > mapSize || next.c > mapSize)
			continue;
		if (visited[next.r][next.c])
			continue;
		if (MAP[now.r][now.c] <= MAP[next.r][next.c]){
			if (isDig)
				continue;
			else if ((MAP[next.r][next.c] - K) >= MAP[now.r][now.c])
				continue;
			else{
				MAP[next.r][next.c] -= 1;
				isDig = 1;
			}
		}
		visited[next.r][next.c] = step;
		dfs(next, isDig, step + 1);
	}
	// cout << dist << '\n';
}
