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
    string a;
    cin >> a;
    vector<int> ps(a.size()+1);
    ps[0] = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] == '0') {
            ps[i+1] = 0;
        } else {
            ps[i+1] = (ps[i] + 1);
        }
    }
    vector<int> ss(a.size()+1);
    ss[n] = 0;
    for(int i = n-1; i >= 0 ; --i) {
        if(a[i] == '0') {
            ss[i] = 0;
        } else {
            ss[i] = (ss[i+1] + 1);
        }
    }
    int m = 0;
    for(int i = 0; i <= n-k; ++i) {
        m = max(m, ps[i] + k + ss[i+k]);
    }
    cout << m << '\n';

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
