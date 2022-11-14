#include <iostream>
#include <queue>
#define INF 2134567890
using namespace std;

int TestCase, N;
int Ans = INF;
int Map[15][15];
int Visit[15][15];
int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};
struct Pos{ int r, c, time; } Start, Finish;

void init(){
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++){
            Map[r][c] = 0;
            Visit[r][c] = 0;
        }

    Ans = INF;
}

void bfs(Pos start){
    queue<Pos> q;
    q.push(start);

    while (!q.empty()){
        Pos now = q.front();
        q.pop();
        Visit[now.r][now.c] = now.time;

        if (now.r == Finish.r && now.c == Finish.c){
            Ans = min(Ans, now.time);
            continue;
        }

        for (int i = 0; i < 4; i++){
            Pos next = {now.r + dR[i], now.c + dC[i]};
            if (next.r < 0 || next.r >= N)  continue;
            if (next.c < 0 || next.c >= N)  continue;
            if (Visit[next.r][next.c] != 0) continue;
            if (Map[next.r][next.c] == 1)   continue;
            
            int nextTime = now.time;
            if (Map[next.r][next.c] == 2 && (nextTime % 3 != 2)){
                while (nextTime % 3 != 2) { nextTime++; }
            }
            next.time = nextTime + 1;
            q.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> N;

        for (int row = 0; row < N; row++)
            for (int col = 0; col < N; col++)
                cin >> Map[row][col];

        cin >> Start.r >> Start.c >> Finish.r >> Finish.c;

        bfs(Start);

        Ans = Ans == INF ? -1 : Ans;
        cout << "#" << tc << " " << Ans << '\n';
        init();
    }

    return 0;
}

/*
[입력]
- 첫 번째 줄:  테스트 케이스 수 T
- 각 테스트 케이스의 첫 번째 줄: 수영장의 크기 N  (2 <= N <= 15)
- 다음 N개의 줄의 i번째 줄에는 수영장의 모양이 공백으로 구분되어 주어진다 
  ( 0: 지나갈 수 있는 곳, 1: 장애물, 2:주기가 2초인 소용돌이)
- 다음으로 시작위치 A,B가 주어지고 (0 <= A,B <= N-1)
- 마지막 줄에 도착위치 C, D가 주어진다 (0 <= C,D <= N-1) 
  ( 도착점과 시작점은 소용돌이가 아니다 )

[출력]
- 각 테스트 케이스마다 '테스트 케이스의 번호'와 '이동시간'을 공백을 두고 표시
- 도착 할 수 없다면 '-1'을 출력한다.
(Ex) #1 4

[조건]
- 섬과 같은 지나갈 수 없는 장애물, 주기적으로 사라졌다 나타나는 소용돌이 존재
  장애물: 1, 소용돌이: 2
- 소용돌이는 생성되고 2초간 유지 1초 동안 잠잠
- ex) 0초에 생성된 소용돌이
      0초: 생성 및 유지
      1초: 유지
      2초: 사라짐 
      3초: 생성 및 유지
      4초: 유지 
      5초: 사라짐
      ...
- *단, 한번 통과한 소용돌이 위에서는 머물러 있을 수 있다

[풀이]
- bfs
- Pos : { int r, c, time; }
- queue<Pos> q; 
- 종료조건: now == finish
- 가지치기: 지도밖/장애물
- 추가조건: 소용돌이(Map[r][c]==2) 대상 time % 3 == 2 인 경우 소용돌이 잦아들 때까지 기다림
- next.time 업데이트 (now.time + 기다린 시간 + 1(다음 스텝))
- q.push(next)

*/