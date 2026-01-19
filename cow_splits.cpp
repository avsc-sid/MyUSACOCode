#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

string removeChar(const string& str, char letter) {
  string ret;
  ret.reserve(2);
  for (char l : str) if (l != letter) ret.push_back(l);
  return ret;
}

int main() {
  int T, k;
  long N, L, i, j, M, hBlocks, hLen, index, index2;
  cin >> T >> k;
  while (T--) {
    string S;
    cin >> N >> S;
    L = 3*N;

    if (N%2 == 1) {
      cout << -1 << endl;
      continue;
    }

    hBlocks = N/2;
    hLen = 3*hBlocks;

    if (S.substr(0, hLen) == S.substr(hLen, hLen)) {
      cout << 1 << endl;
      for (i = 0; i < L-1; ++i) cout << 1 << " ";
      cout << 1 << endl;
      continue;
    }

    const string letters = "COW";
    vector<int> output(L,2);

    for (i = 0; i < hBlocks; ++i) {
      index = 3*i;
      index2 = hLen + index;

      string A = S.substr(index,3);
      string B = S.substr(index2, 3);
      char chosenLetter = 0;
      for (char l : letters) {
        if (removeChar(A, l) == removeChar(B, l)) {
          chosenLetter = l;
          break;
        }
      }

      for (j = 0; j < 3; ++j) {
        if (S[index + j] == chosenLetter) output[index+j] = 1;
        if (S[index2 + j] == chosenLetter) output[index2+j] = 1;
      }
    }

    cout << 2 << endl;
    for (i = 0; i < L-1; ++i) {
      cout << output[i] << " ";
    }
    cout << output[L-1] << endl;
  }
}
