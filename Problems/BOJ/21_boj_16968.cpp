#include <iostream>

using namespace std;

int dfs(string &format, int idx, int bf)
{
	if (format.size() == idx){ return 1; }

	/*
		문자 형식 : a ~ z
		숫자 형식 : 0 ~ 9
	*/
	int strt = (format[idx] == 'c' ? 'a' : '0');
	int end = (format[idx] == 'c' ? 'z' : '9');

	int total = 0;
	for (char i = strt; i <= end; ++i){
		// 앞문자와 중복되지 않으면 경우의 수 카운팅
		if (i != bf){ 
            total += dfs(format, idx + 1, i); 
        }
	}
	return total;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    freopen("../SampleInput/input.txt", "r", stdin);

	// 입력
	string format;
	cin >> format;

	// dfs 브루트포스로 가능한 모든 경우의 수 구하기
	cout << dfs(format, 0, ' ');


	return 0;
}