#include <bits/stdc++.h>
using namespace std;

#define D(x) cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> bs(31, 0);
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        for(int j = 0; j < 31; ++j) {
            if(a & (1 << j)) {
                ++bs[j];
            }
        }
    }

    int r = 0;

    for(int i = 30; i >= 0; --i) {
        if(k >= n - bs[i]) {
            r |= 1 << i;
            k -= n - bs[i];
        }
    }

    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while(tests-- > 0) {
        solve();
    }

}
