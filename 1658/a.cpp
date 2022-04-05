#include <bits/stdc++.h>
#include <numeric>

#define D(x) //cout << #x << ": " << (x) << '\n';

using namespace std;

using ll = long long;

void solve() {
  int l, r;
  cin >> l >> r;
  int n = r - l + 1;
  if(n % 2 == 1) {
    int x = 0;
    for (int i = l; i <= r; ++i) {
        unsigned int t;
        cin >> t;
        x ^= i ^ t;
    }
    cout << x << '\n';
    return;
  }
  array<int, 18> b;
  b.fill(0);

  vector<unsigned> v;

  for (int i = l; i <= r; ++i) {
    unsigned int t;
    cin >> t;
    v.push_back(t);
    D(t)
    for (int j = 0; j < 18; ++j) {
      unsigned m = 1 << j;
      D(m);
      b[j] += ((m & t) != 0)?1:0;
      D(b[j])
    }
  }

  unsigned int x = 0;


  for (int i = 1; i < 18; ++i) {
      if(b[i] > (n/2)) {
          x |= 1 << i;
      }
  }

  for(auto& a : v) {
      a ^= x;
      if(a > r || a < l) {

      }
  }

  cout << x << '\n';

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t > 0) {
    solve();
    --t;
  }
}
