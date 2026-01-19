
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
  int N, K, Q, i, j;
  cin >> N >> K >> Q;
  int r, c, bound;
  bound = N - K + 1;
  long v, d;
  long long thisSum, largestSum = 0;
  vector<vector<long>> field(N, vector<long>(N, 0));
  vector<vector<long long>> prefixSum(bound, vector<long long>(bound, 0));

  while (Q--) {
    cin >> r >> c >> v;
    --r;
    --c;

    d = v - field[r][c];
    field[r][c] = v;

    int r_low  = max(0, r - K + 1);
    int r_high = min(r, N - K);
    int c_low  = max(0, c - K + 1);
    int c_high = min(c, N - K);

    for (i = r_low; i <= r_high; ++i) {
        for (j = c_low; j <= c_high; ++j) {
            prefixSum[i][j] += d;
            if (prefixSum[i][j] > largestSum) {
                largestSum = prefixSum[i][j];
            }
        }
    }


    cout << largestSum << endl;
  }
}
