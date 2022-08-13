#include <bits/stdc++.h>
using namespace std;

#define D(x) //cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

vector<ll> un;
int n;
int nn;
ll query(int l, int r) {
    D(l);
    D(r);
    D(un[l]);
    l += nn;
    r += nn;
    ll res = un[l];
    while(r > l) {
        if(l&1) res = gcd(res, un[l++]);
        if(r&1) res = gcd(res, un[--r]);
        l /= 2;
        r /= 2;
    }
    D(res);
    return res;
}


void solve() {
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<ll> as(n-1);
    nn = 1;
    while(nn < n-1) nn <<= 1;
    un.clear();
    un.resize(nn*2);
    for(int i = 0; i < n-1; ++i) {
        as[i] = a[i] - a[i+1];
        un[nn+i] = as[i];
    }
    for(int i = nn-1; i > 0; --i) {
        un[i] = gcd(un[2*i], un[2*i+1]);
    }
    int l = 0, s = 2;
    while(l + s - 1 < n) {
        D(l)
        D(s)
        if(abs(query(l, l+s-1)) != 1) {
            ++s;
        } else {
            ++l;
        }
    }
    cout << s-1 << '\n';
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
