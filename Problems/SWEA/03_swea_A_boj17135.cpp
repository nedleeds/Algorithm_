#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct enemy {
    int x, y, dis;
};
int n, m, d;
int orip[17][17], p[17][17];
int dis;
vector<int> archer;
vector<pair<int, int>> present(3);
enemy min_enemy[3];

void checking(int& enemynum) {
    enemynum = 0;
    min_enemy[0] = { -1, -1, 100 };
    min_enemy[1] = { -1, -1, 100 };
    min_enemy[2] = { -1, -1, 100 };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (p[i][j] == 0) continue;
            ++enemynum;
            for (int k = 0; k < 3; ++k) {
                dis = abs(present[k].first - i) + abs(present[k].second - j);
                if (dis > d) continue;    // 최소거리 넘으면
                if (min_enemy[k].dis == dis && min_enemy[k].y < j) continue;    // 가장 왼쪽값 아니면
                if (min_enemy[k].dis >= dis) min_enemy[k] = { i, j, dis };
            }
        }
    }
}
void kill(int& killnum) {
    killnum = 0;
    for (int i = 0; i < 3; ++i) {
        if (min_enemy[i].x < 0) continue;
        if (p[min_enemy[i].x][min_enemy[i].y] == 0) continue; // 앞 궁수가 미리 죽인 것
        p[min_enemy[i].x][min_enemy[i].y] = 0; // kill
        killnum++;
    }
}

void move(int& gonenum) {
    gonenum = 0;
    int tmp[17] = { 0, }, gone = 0;
    for (int i = 0; i < n; ++i) {
        swap(tmp, p[i]);
    }
    for (int i = 0; i < m; ++i)
        gone += p[n - 1][i];
}

int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> orip[i][j];
    archer.push_back(1);
    archer.push_back(1);
    archer.push_back(1);
    while (archer.size() < m) {
        archer.push_back(0);
    }

    int res = 0;
    do {
        copy(&orip[0][0], &orip[0][0] + (17 * 17), &p[0][0]);
        for (int i = 0, ind = 0; i < m; ++i) {
            if (archer[i] == 1) {
                present[ind] = { n, i };
                ind++;
            }
        }
        int num = 0, enemynum, killnum, gonenum;
        while (true) {
            checking(enemynum);
            kill(killnum);
            move(gonenum);
            num += killnum;

            if (enemynum - (killnum + gonenum) == 0)
                break;
        }
        res = max(res, num);
    } while (prev_permutation(archer.begin(), archer.end()));

    cout << res << '\n';
    return 0;
}    
