#include <iostream>
#define INF 2134567890
using namespace std;

int T, X, Y;
int MinCost = INF;
int CostX, CostY, CostZ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> CostX >> CostY >> CostZ >> X >> Y;

    for (int j = 0; j <= 100000; j++){
        int cost = (CostX * max(0, X - j) + CostY * max(0, Y - j) + CostZ * (j * 2));
        MinCost = min(MinCost, cost);
    }

    cout << MinCost << '\n';
    MinCost = INF;

    return 0;
}

/*

해맸던 이유:
첫번째 접근 : 보고 어? dfs 인가? 기저조건을 건드려야되나? (고질적인 문제)
해설을 조금 봄 : 아 ... 이게 식을 간단하게 세울수가 있구나
두번째 접근 : 반반 치킨의 수를 가지고 접근하면, 짝수 개수 일 때만 동작해야되는데?
           그리고 후라이드, 양념 빼다가 음수나오면 처리해야되는데??
           조건 열심히 처리하다가 -> 멘붕...? 뭔가에 씌인듯..
해설을 마저 봄 : max(0, X - j) 로 정말 간단하게 음의 개수를 처리함
세번째 접근 : z를 총 몇 번 돌아야 하는가? 에서 막혔음
           100000'까지' 돌면 된다
           근데 굳이? 주어진 X, Y 에서 max 값을 뽑아서 그만큼만 돌면 최소 마리수를 비교할 수 있다
*/