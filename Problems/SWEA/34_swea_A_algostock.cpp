#include <iostream>
#include <vector>
using namespace std;

// Ms(예치금), Ma(월 불입금), N(종목수), L(데이터기간), MaxSell(내달 최대 판매액)
int TestCase, Ms, Ma, N, L, MaxSell;
vector<vector<int>> Stock;

// dfs 목적: 각 종목 별로 몇 주를 사는 것이 내달 최대 이익인지 판단
// month: 현재 월, balance: 잔액, sell: 내달 판매액(=> month + 1)
void dfs(int month, int balance, int sell){ 
    if (MaxSell < balance + sell) { MaxSell = balance + sell; }
    if (balance == 0) { return; }

    for (int i = 0; i < N; i++){
        // 1. 구입 가능한가 - 잔액 >= 이달 주가
        // 2. 다음 달에 주가가 상승하는가 - 내달 주가 > 이달 주가
        if (balance >= Stock[i][month] && Stock[i][month + 1] > Stock[i][month]){
            dfs(month, balance - Stock[i][month], sell + Stock[i][month + 1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> Ms >> Ma >> N >> L;

        // 2차원 벡터 동적 할당
        Stock.resize(N, vector<int>(L+1, 0));
        for (int r = 0; r < N; r++)
            for (int c = 0; c < L + 1; c++)
                cin >> Stock[r][c];
        
        // 매달 최대 잔액(balance)을 갖도록 완탐 구성
        int balance = Ms; // 0월 -> 잔액: 예치금
        for (int month = 0; month < L; month++){
            MaxSell = 0;             // 이달 최대 판매액 초기화
            dfs(month, balance, 0);  // 이달 최대 판매액 계산
            balance = MaxSell + Ma;  // 이달 최대 잔액 갱신
        }

        int ans = balance - (Ms + Ma * L);
        cout << "#" << tc << " " << ans << '\n';

        // 2차원 벡터 초기화
        for (int r = 0; r < N; r++)
            Stock[r].clear();
        Stock.clear();
    }

    return 0;
}

