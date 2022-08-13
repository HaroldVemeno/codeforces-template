#include <bits/stdc++.h>
using namespace std;

#define D(x) //cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = unsigned long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

int md = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> as(n);
    vector<ll> ns(n);
    vector<ll> ts(n);
    vector<vector<int>> in(n);
    vector<int> ind(n);
    vector<vector<int>> out(n);
    for(int i = 0; i < n; ++i) {
        cin >> as[i];
    }
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        in[y].push_back(x);
        out[x].push_back(y);
    }
    ll t;
    vector<int> emp{};
    for(int i = 0; i < n; ++i) {
        if(in[i].empty()) {
            emp.push_back(i);
        }
    }

    while(!emp.empty()) {
        int a = emp.back();
        emp.pop_back();
        for(auto b : out[a]) {
            ++ind[b];
            if(as[b] )
            if(ind[b] == in[b].size()) {
                emp.push_back(b);
            }
            as[b] += as[a];
        }
    }

    cout << (*max_element(all(as))%md) << '\n';
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
