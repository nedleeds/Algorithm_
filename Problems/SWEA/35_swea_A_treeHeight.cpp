#include <iostream>
#include <vector>
using namespace std;

int TestCase, N;
vector<int> tree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(), cout.tie();

    freopen("../SampleInput/input.txt", "r", stdin);

    cin >> TestCase;
    for (int tc = 1; tc <= TestCase; tc++){
        cin >> N;

        // 나무 높이 입력
        int maxH = 0;
        tree.resize(N, 0);
        for (int i = 0; i < N; i++) { 
            cin >> tree[i]; 
            if (maxH < tree[i]){ maxH = tree[i]; }
        }

        // 나무 높이 차(홀/짝) 세팅
        // 나무 별로 높이 차가 홀수인 경우 
        // 첫 날을 제외한 나머지는 짝수 번째 날은 홀수 번째 날로 대체 가능하다
        // 따라서 전체 나무들 중 높이 차가 홀수인 나무의 수를 파악해서
        // 전체 물을 줘야하는 날들(days)에 대해서 홀수 먼저 물을 주고
        // 남아있는 짝수 차이의 높이들을 홀수 차이로 대체가능한지 체크하면서 물을 준다

        int odd = 0;    // 홀수 번째 날 물을 주는 '횟수'
        int even = 0;   // 짝수 번째 날 물을 주는 '횟수'
        for (auto height: tree){
            int diff = maxH - height;
            odd += diff % 2;
            even += diff / 2;
        }

        int days = 0;   // 전체 물을 줘야하는 날들
        if (odd > 0){   // 대체불가인 홀수 번째 먼저 
            // 높이 차가 홀수인 경우
            days = 2 * odd - 1; // 전체 날짜 중 필수 홀수 번째 날들 먼저 물을 준다
            if (even >= odd){   // 짝수 번째 날 물을 주는 횟수가 홀수 번째 날보다 더 많으면
                days += 1;      // 우선, 필수로 줘야하는 홀수 번째 다음날까지만 물을 준다(이틀 단위)
                even -= odd;    // 홀수 번째 만큼 짝수 번째도 물을 준 상황이므로 남아있는 짝수 횟수에서 차감
            }
            else{
                // 짝수 번째 날 물을 주는 횟수가 홀수 번째 날보다 더 적으면
                // 홀수 번째 이전에 이미 짝수 번째 물을 다 줘서 추가로 더 줄 짝수 횟수는 0이 된다
                even = 0;
            }
        }
        // 성장 시켜야할 키가 더 남아있는 경우
        // 짝수 -> 홀수로 대체 시, '홀' 짝 '홀' (3일)로 묶여진다
        // 따라서, 성장해야할 키를 3일 단위로 계산하여
        // 채울 만큼 채우고 나머지는 더해주는 방식으로 계산한다
        if (even > 0){
            int growth = even * 2;  // 남은 성장해야할 "키"
            days += growth / 3 * 2; // 남은 "키"를 "이틀" 단위("+1,+2 = +3")로 처리
            days += growth % 3;     // 이틀 성장하고 남은 나머지 키는 0, 1, 2 (1일 +1, 2일 +2) 즉, 키 == 날짜가 된다
        }

        cout << "#" << tc << " " << days << '\n';

        // 나무 높이 초기화
        tree.clear();
    }

    return 0;
}