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
    ll x, y;
    cin >> x >> y;
    ll ml, mr;
    if(x & 1) {
        ml = x / 2;
        mr = ml + 1;
    } else {
        ml = x / 2;
        mr = ml;
    }
    D(ml)
    D(mr)
    ll nl;
    for(int i = sqrt(y); i >= 0; --i) {
        D(i)
        if(y % i == 0) {
            nl = i;
            break;
        }
        if(i == 0) {
            cout << "-1\n";
            return;
        }
    }
    ll nr;
    if(nl == 0) {
        nr = 0;
    } else {
        nr = y / nl;
    }
    D(nl)
    D(nr)
    if(nr < ml || mr < nl) {
        cout << ml << ' ' << mr << '\n';
        cout << nl << ' ' << nr << '\n';
    } else {
        cout << "-1\n";
    }
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
