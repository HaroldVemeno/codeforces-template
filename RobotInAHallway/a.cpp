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
    int m;
    cin >> m;
    vector<int> as(m);
    vector<int> bs(m);
    for(int i = 0; i < m; ++i) {
        cin >> as[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> bs[i];
    }
    int r = -1;
    vector<int> snake;
    snake.reserve(2*m);
    for(int i = 0; i < m; ++i) {
        if(i&1) {
            r = max(r+1, bs[i]);
            snake.push_back(r);
            r = max(r+1, as[i]);
            snake.push_back(r);
        } else {
            r = max(r+1, as[i]);
            snake.push_back(r);
            r = max(r+1, bs[i]);
            snake.push_back(r);
        }
    }
    vector<pair<int, int>> ah;
    ah.reserve(m);
    if(as[m-1] < bs[m-1]) ah.push_back({bs[m-1], 1});
    else ah.push_back({as[m-1], 0});
    for(int i = m-2; i >= 0; --i) {
        int d = (m - i - 1) * 2 + 1;
        int m = ah.back().first;
        int p = ah.back().second + 1;
        if(as[i] > m - p) {
            m = as[i];
            p = 0;
        }
        if(bs[i] - d > m - p) {
            m = bs[i];
            p = d;
        }
        ah.push_back({m, p});
    }
    vector<pair<int, int>> bh;
    ah.reserve(m);
    if(bs[m-1] < as[m-1]) bh.push_back({as[m-1], 1});
    else bh.push_back({bs[m-1], 0});
    for(int i = m-2; i >= 0; --i) {
        int d = (m - i - 1) * 2 + 1;
        int m = bh.back().first;
        int p = bh.back().second + 1;
        if(bs[i] > m - p) {
            m = bs[i];
            p = 0;
        }
        if(as[i] - d > m - p) {
            m = as[i];
            p = d;
        }
        bh.push_back({m, p});
    }
    D(snake)
    // for(int i = 0; i < m; ++i) {
    //     D(ah[i].first)
    //     D(ah[i].second)
    // }
    // for(int i = 0; i < m; ++i) {
    //     D(bh[i].first)
    //     D(bh[i].second)
    // }
    int rs = snake[m*2-1];
    for(int i = m-2; i >= m; --i) {
        int d = (m - i - 1) * 2 + 1;
        rs = min(rs, max(snake[i]));
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
