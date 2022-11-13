#include <iostream>
#include <vector>
using namespace std;

int TestCase, N;
char Map[300][300];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(), cout.tie();

  freopen("../SampleInput/input.txt", "r", stdin);

  cin >> TestCase;

  for (int tc = 1; tc < TestCase; tc++) {
    cin >> N;
    for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
            cin >> Map[r][c];
    
    int de = 1;
    reset();
  }

  return 0;
}