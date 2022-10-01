// #include <iostream>
// #include <vector>
// using namespace std;

// int testCase;
// int mapSize, depth;
// int MAP[10][10];
// int maxHeight = -2134567890;
// struct Node{ int r, c; } node;
// vector<Node> maxNodes;


// void printMap(int M[10][10]);
// void setMap();
// void dfs(int now);
// void findRoad();
// void setMaxNodes(Node n);
// /*
// 1
// 5 1       
// 9 3 2 3 2 
// 6 3 1 7 5
// 3 4 8 9 9
// 2 3 7 7 7
// 7 6 5 5 8
// */
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie();
// 	cout.tie();

// 	cin >> testCase;
// 	cin >> mapSize;

// 	for (int tc=0; tc<testCase; tc++){
// 		setMap();
// 		// findRoad();
// 	}

// 	return 0;
// }

// void printMap(int M[10][10]){
// 	for (int row=0; row<10; row++){
// 		for (int col=0; col<10; col++)
// 			cout << M[row][col] << ' ';
// 		cout << "\n";	
// 	}
// }


// void setMap(){
// 	int maxHeight = -2134567890;
// 	int preMax = maxHeight; 
// 	for (int row=1; row<=mapSize; row++){
// 		for (int col=1; col<=mapSize; col++){
// 			cin >> MAP[row][col];
// 			setMaxNodes({row, col});
// 		}
// 	}
// }

// // void setMaxNodes(Node n){
// // 	if (maxHeight < MAP[n.r][n.c]){
// // 		maxHeight = MAP[n.r][n.c];
// // 		maxNodes.push_back(n);
// // 	}else if (maxHeight == MAP[n.r][n.c])
// // 	{
		
// // 	}
	
// // }

// // void dfs(int now){

// // }

// // void findRoad(){
// // 	// dfs();
// // }