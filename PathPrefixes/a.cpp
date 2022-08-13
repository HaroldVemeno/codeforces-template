#include <bits/stdc++.h>
using namespace std;

#define D(x) cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

vector<vector<int>> sl;
vector<int> p;
vector<int> a;
vector<int> at;
vector<int> b;
vector<int> bt;
vector<int> rs;
vector<int> d;

void solve() {
    int n;
    cin >> n;
    sl.resize(n);
    p.resize(n);
    a.resize(n);
    at.resize(n);
    b.resize(n);
    bt.resize(n);
    rs.resize(n);
    d.resize(n);
    d[0] = 0;
    p[0] = -1;
    at[0] = 0;
    bt[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i] >> a[i] >> b[i];
        sl[p[i]].push_back(i);
    }
    vector<int> st;
    vector<int> lvs;
    while(!st.empty()) {
        int n = st.back(); st.pop_back();
        for(auto s : sl[n]) {
            at[s] = at[n] + a[s];
            bt[s] = bt[n] + b[s];
            d[s] = d[n] + 1;
            st.push_back(s);
        }
        if(sl[n].empty()) {
            lvs.push_back(n);
        }

    }
    for(int i = 1; i < n; ++i) {
        cout << rs[i] << ' ';
    }
    cout << '\n';
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
