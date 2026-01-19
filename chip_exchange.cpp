#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
  long long A, B, Ca, Cb, Fa, i, maxTrades, additionalAChips, additionalBChips, output;
  int T;
  cin >> T;
  for (i = 0; i < T; ++i) {
    cin >> A >> B >> Ca >> Cb >> Fa;

    maxTrades = B/Cb;
    A += maxTrades * Ca;
    B -= maxTrades * Cb;

    if (A >= Fa) {
      cout << 0 << endl;
      continue;
    }

    additionalAChips = Fa-A;

    if (Ca >= Cb) {
      output = additionalAChips-1 + Cb;
      cout << output << endl;
      continue;
    }

    maxTrades = 1 + (additionalAChips-1)/Ca;
    additionalBChips = maxTrades*Cb-B-1;
    maxTrades = additionalBChips/Cb;
    A += maxTrades * Ca;
    output = additionalBChips + (Fa-A);

    cout << output << endl;
  }
}
