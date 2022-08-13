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
    int m;
    int la;
};

S un[550000];
int n;
int nn;

// clopen interval
int go(int l, int r, int add = 0, int lu = 0, int ru = nn, int ui = 1) {
    D(l)
    D(r)
    D(lu)
    D(ru)
    if(ru <= l || r <= lu || r < l || lu >= n) return 1000001;
    if(un[ui].la > 0) {
        if(ui <= nn) {
            un[ui*2].la += un[ui].la;
            un[ui*2].m += un[ui].la;
            un[ui*2+1].la += un[ui].la;
            un[ui*2+1].m += un[ui].la;
        }
        un[ui].la = 0;
    }
    if(l <= lu && r >= ru) {
        un[ui].m += add;
        un[ui].la += add;

        return un[ui].m;
    }

    int m1 = go(l, r, add, lu, (lu+ru)/2, ui*2);
    int m2 = go(l, r, add, (lu+ru)/2, ru, ui*2+1);

    un[ui].m = min(un[ui*2].m, un[ui*2+1].m);

    return min(m1, m2);
}

void solve() {
    cin >> n;
    nn = 1;
    while(nn < n) nn *= 2;
    for(int i = 0; i < n; ++i) {
        cin >> un[nn + i].m ;
        un[nn + i].la = 0;
    }
    for(int i = n; i < nn; ++i) {
        un[nn + i].la = 0;
        un[nn + i].m = 1000001;
    }
    for(int i = nn-1; i > 0; --i) {
        un[i].m = min(un[2*i].m, un[2*i+1].m);
        un[i].la = 0;
    }
    int q;
    cin >> q;
    cin.ignore(23423, '\n');
    int oi = 0;
    for(int i = 0; i < q; ++i) {
        for(int j = 0; j < nn*2; ++j) {
            D(j)
            D(un[j].m);
            D(un[j].la);
        }
        string s;
        getline(cin, s, '\n');
        int mez = 0;
        for(auto c : s) {
            if(c == ' ') ++mez;
        }
        stringstream ss{s};
        int l, r;
        ss >> l >> r;
        if(mez == 1) {
            if(l <= r) {
                cout << go(l, r+1);
            } else {
                cout << min(go(0, r+1), go(l, n));
            }
            cout << '\n';
        } else if (mez == 2) {
            oi++;
            D(oi);
            int v;
            ss >> v;
            if(l <= r) {
                go(l, r+1, v);
            } else {
                go(0, r+1, v); go(l, n, v);
            }
        } else {
            cerr << "badbadbad" << '\n';
        }
    }




}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    solve();
}
