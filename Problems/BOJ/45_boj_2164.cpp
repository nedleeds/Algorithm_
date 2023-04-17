#include <iostream>
#include <queue>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> N;

    queue<int> q;
    int num = 1;
    while(num <= N){
        q.push(num++);
    }

    while(q.size() > 1){
        q.pop();

        int x = q.front();
        q.pop();
        q.push(x);
    }

    cout << q.front() << '\n';

    return 0;
}