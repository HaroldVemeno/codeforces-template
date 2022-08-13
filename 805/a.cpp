#include <bits/stdc++.h>
using namespace std;

#define D(x) cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

struct S {
    vector<int> as;
    int c = 0;
};


void solve() {
    int n; cin >> n;
    vector<int> as;
    vector<int> bs;
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        while(!(a&1)) {
            a /= 2;
        }
        as.push_back(a);
    }
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        while(!(a&1)) {
            a /= 2;
        }
        bs.push_back(a);
    }
    sort(all(as));
    sort(all(bs));
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
