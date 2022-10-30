#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

bool isBigger(void* q, int highest){
	queue<PII> rankQ = *(queue<PII> *)q;

	bool flag =false;
	for (int i = 0; i < rankQ.size(); i++){
		PII rank = rankQ.front();
		rankQ.pop();

		if (highest < rank.first)
			flag = true;

		rankQ.push(rank);
	}
	return flag;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen("../SampleInput/input.txt", "r", stdin);

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++){
		int n, m;
		cin >> n >> m;

		// get input
		queue<PII> rankQ, printQ;
		for (int pos = 0; pos < n; pos++){
			PII ranking;
			cin >> ranking.first;
			ranking.second = pos;
			rankQ.push(ranking);
		}

		int cnt = 0;
		while(!rankQ.empty()){
			PII rankNow = rankQ.front();
			rankQ.pop();

			// if there is bigger element -> push
			if (isBigger(&rankQ, rankNow.first)){
				rankQ.push(rankNow);
			}
			// else -> print !
			else{
				cnt++;
				if (rankNow.second == m) break;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}