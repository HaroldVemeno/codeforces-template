#include <bits/stdc++.h>
using namespace std;

#define D(x) cerr << #x << ": " << x << '\n';
#define all(x) begin(x), end(x)
using ll = int64_t;
//#define int ll

void solve() {
    int n; cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        s.insert(t);
    }
    while(true) {
        if(s.size() <= 1) {
            cout << "YES\n";
            return;
        }
        int a = *(s.begin());
        int b = *(++s.begin());

        if(abs(a - b) <= 1) {
            s.erase(s.begin(), ++++s.begin());
            s.insert(a+b);
        } else {
            cout << "NO\n";
            return;
        }


    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while(tests-- > 0) {
        solve();
    }

}
