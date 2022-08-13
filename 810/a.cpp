#include <bits/stdc++.h>
using namespace std;

#define D(x) cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

struct P {
    int i;
    int x;
    int p;
    int h;
    int dn;
    int dp;
    int nx;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<P> s{};

    for(int i = 0; i < n; ++i) {
        int x, p;
        cin >> x >> p;
        s.push_back({i, x, p, p});
    }

    sort(all(s), [](const P& a, const P& b){return a.x < b.x;});
    for(int i = 0; i < n; ++i) {
        s[i].nx = i;
    }
    s[0].dp = 0;
    s[n-1].dn = 0;
    for(int i = 0; i < n-1; ++i) {
        s[i].dn = s[i+1].x - s[i].x;
        s[i+1].dp = s[i+1].x - s[i].x;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int age = 0;
    int pa = 0;

    for(int i = 0; i < n; ++i) {
        age += s[i].dp;
        pa -= s[i].dp*pq.size();
        while(!pq.empty() && pq.top() - age <= 0 ) {
            pa -= pq.top() - age;
            pq.pop();
        }
        s[i].h += pa;
        pa += s[i].p + age;
        pq.push(s[i].p + age);
    }
    age = 0;
    pa = 0;
    while(!pq.empty()) {
        pq.pop();
    }


    for(int i = n-1; i >= 0; --i) {
        age += s[i].dn;
        pa -= s[i].dn*pq.size();
        while(!pq.empty() && pq.top() - age <= 0 ) {
            pa -= pq.top() - age;
            pq.pop();
        }
        s[i].h += pa;
        pa += s[i].p + age;
        pq.push(s[i].p + age);
    }

    vector<bool> bs(n, true);

    age = 0;
    pa = 0;
    bool npws = false;
    int npw;

    for(int i = 0; i < n; ++i) {
        age += s[i].dp;
        if(m < s[i].h-s[i].p) {
            bs[i] = false;
            continue;
        }
        if(npws && s[i].p < npw + age) {
            bs[i] = false;
            continue;
        }
        if(s[i].h > m) {
            if(!npws) {
                npws = true;
                npw = s[i].h - age - m;
            }
            npw = max(npw, s[i].h - age - m);
        }
    }

    age = 0;
    npws = false;
    for(int i = n-1; i >= 0; --i) {
        age += s[i].dn;
        if(m < s[i].h-s[i].p) {
            bs[i] = false;
            continue;
        }
        if(npws && s[i].p < npw + age) {
            bs[i] = false;
            continue;
        }
        if(s[i].h > m) {
            if(!npws) {
                npws = true;
                npw = s[i].h - age - m;
            }
            npw = max(npw, s[i].h - age - m);
        }
    }

    for(int i = 0; i < bs.size(); ++i) {
        if(bs[i]) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << '\n';


    for(int i = 0; i < n; ++i) {
        D(s[i].i)
        D(s[i].x)
        D(s[i].nx)
        D(s[i].p)
        D(s[i].h)
        D(s[i].dp)
        D(s[i].dn)
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
