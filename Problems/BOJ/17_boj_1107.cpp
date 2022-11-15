#include <iostream>
using namespace std;

int target;
int errCnt, btn;
bool errors[10] = { false };

int countPress(int num) {
    int cnt = 0;
    // 0 -> hanling
    if (num == 0) {
        if (errors[0])
            return -1;
        return 1;
    }
    // 0 < num, press the button
    while (num) {
        if (errors[num % 10]) // is error
            return -1;
        num /= 10;
        cnt++; // count: length of num
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    // target
    cin >> target;

    // check error button
    cin >> errCnt;
    for (int i = 0; i < errCnt; i++) {
        cin >> btn;
        errors[btn] = true;
    }

    // check start(100) and target is same
    if (target == 100) {
        cout << "0\n";
        return 0;
    }

    int ans = abs(target - 100);
    for (int i = 0; i <= 999999; i++) {
        int cnt = countPress(i);
        if (cnt > 0) {
            // if no error button
            ans = min(ans, cnt + abs(target - i));
        }
    }
    cout << ans << '\n';
    return 0;
}