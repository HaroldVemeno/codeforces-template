#include <bits/stdc++.h>
using namespace std;

#define D(x) cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

bool check(int n, ll p, ll q) {
    if(n==0 && q == 0) return true;
    else if (n==0) return false;
    ll a;
    cin >> a;
    if(q == 0) return false;
    ll d = p / q;
    ll r = p % q;
    ll t;
    D(n)
    D(p)
    D(q)
    D(d)
    D(r)
    D(a)

    if(n == 2 && a == d-1 && r == 0 && q == 1 && (cin >> t, t == 1)) return true;
    if(d != a) return false;
    return check(n-1, q, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll p, q;
    int n;
    cin >> p >> q >> n;
    cout <<  ((check(n, p, q)) ? "YES" : "NO") << '\n';
    return 0;
}
