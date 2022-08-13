#include <bits/stdc++.h>
using namespace std;

#define D(x) //cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

int n;
int mt[1000][1000];
int mt2[1000][1000];

void swp(int m[1000][1000], int k) {
    for(int i = 0; i < n; ++i) {
        swap(m[i][k], m[k][i]);
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> mt[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            mt2[i][j] = mt[i][j];
        }
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int a = i*n + j;
            int b = j*n + i;
            if(a < b) {
                if(mt[i][j] > mt[j][i]) {
                    swp(mt, i);
                    break;
                } else if(mt[i][j] == mt[j][i]) {
                    continue;
                } else break;
            } else if(a > b) {
                if(mt[i][j] < mt[j][i]) {
                    swp(mt, i);
                    break;
                } else if(mt[i][j] == mt[j][i]) {
                    continue;
                } else break;
            }
        }
    }
    swp(mt2, 0);
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            int a = i*n + j;
            int b = j*n + i;
            if(a < b) {
                if(mt2[i][j] > mt2[j][i]) {
                    swp(mt2, i);
                    break;
                } else if(mt2[i][j] == mt2[j][i]) {
                    continue;
                } else break;
            } else if(a > b) {
                if(mt2[i][j] < mt2[j][i]) {
                    swp(mt2, i);
                    break;
                } else if(mt2[i][j] == mt2[j][i]) {
                    continue;
                } else break;
            }
        }
    }
    for(int i = 0; i < n*n; ++i) {
        if(mt[i / n][i % n] == mt2[i / n][i % n]) continue;
        else if(mt[i / n][i % n] < mt2[i / n][i % n]) break;
        else {
            swap(mt, mt2);
            break;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << mt[i][j] << ' ';
        }
        cout << '\n';
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
