#include <iostream>
#include <queue>
#define LL long long
using namespace std;

LL getMultiple(LL num, LL divider){
    LL d = divider;
    LL cnt = 0;

    while (num % d == 0){
        cnt ++;
        d *= divider;
    }
    return cnt;
}

struct cmp{
    bool operator()(LL a, LL b){
        int a3 = getMultiple(a, 3);
        int b3 = getMultiple(b, 3);
        if (a3 > b3) return false;
        if (a3 < b3) return true;

        int a2 = getMultiple(a, 2);
        int b2 = getMultiple(b, 2);
        if (a2 < b2) return false;
        if (a2 > b2) return true;

        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    int n;
    cin >> n;

    priority_queue<LL, vector<LL>, cmp> pq;
    for (int i = 0; i < n; i++){ 
        LL num; 
        cin >> num;
        pq.push(num);
    }
    
    while(!pq.empty()){
        LL x = pq.top();
        pq.pop();
        
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}

/*
정렬 문제

처음 시도: vector + sort(algorithm)
에러: 시간 초과 
    - sort 에서 getMultiple 함수를 실행하면서 while 문을 O(n^2) 동작

두번째 시도: priority_queue + sort
    - 입력 받음과 동시에 max heap을 적용해서 비교를 nlog(n) 번만 실행
에러: 자료형에서 10^18 이 등장 -> int 범위(20 *1e8)를 넘어섬
    - long long 으로 고치자 해결
*/