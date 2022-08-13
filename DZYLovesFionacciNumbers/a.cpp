#include <bits/stdc++.h>
using namespace std;

#define D(x) //cerr << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using ll = long long;

template<typename T>
ostream& operator <<(ostream& o, const vector<T>& v) {
    bool first = true; o << '['; for(auto& a : v) { if(first) { o << a; first = false; } else { o << ", " << a; } } o << ']'; return o;
}

struct S {
    int s;
    bool l;
    int a;
    int b;
};

S un[1200000];
vector<int> fs;
int n;
int nn;

int md = 1000000009;

int fibbify(int a, int b, int g) {
    if(g == 0) return a;
    if(g == 1) return b;
    int aa =  ((ll)a * fs[g-1]) % md;
    int bb =  ((ll)b * fs[g]) % md;
    return (aa + bb) % md;
}

void push(int lu, int ru, int ui) {
    if(un[ui].l) {
        if(ui < nn) {
            int aa = un[ui].a;
            int bb = un[ui].b;
            int ll = (ru - lu)/2;
            un[ui*2].l = true;
            un[ui*2].a += aa;
            un[ui*2].b += bb;
            un[ui*2].s += fibbify(aa, bb, ll+1) - bb;
            un[ui*2].a %= md;
            un[ui*2].b %= md;
            un[ui*2].s %= md;
            un[ui*2+1].l = true;
            un[ui*2+1].a += fibbify(aa, bb, ll);
            un[ui*2+1].b += fibbify(aa, bb, ll+1);
            un[ui*2+1].s += fibbify(aa, bb, ru - lu + 1) - fibbify(aa, bb, ll+1);
            un[ui*2+1].a %= md;
            un[ui*2+1].b %= md;
            un[ui*2+1].s %= md;
        }
        un[ui].l = false;
        un[ui].a = 0;
        un[ui].b = 0;
    }
}

// clopen interval
void goadd(int l, int r, int lu = 0, int ru = nn, int ui = 1) {
    D(l)
    D(r)
    D(lu)
    D(ru)
    if(ru <= l || r <= lu || r < l || lu >= n) return;
    if(l <= lu && r >= ru) {
        un[ui].l = true;
        D(lu - l + 1)
        un[ui].a += fs[lu - l + 1];
        D(lu - l + 2)
        un[ui].b += fs[lu - l + 2];
        D(ru - l + 2)
        un[ui].s += fs[ru - l + 2] - fs[lu - l + 2];
        if(un[ui].s < 0) un[ui].s += md;
        un[ui].a %= md;
        un[ui].b %= md;
        un[ui].s %= md;

        return;
    }
    push(lu, ru, ui);

    goadd(l, r, lu, (lu+ru)/2, ui*2);
    goadd(l, r,(lu+ru)/2, ru, ui*2+1);

    un[ui].s = un[ui*2].s + un[ui*2+1].s;
    un[ui].s %= md;
}

int query(int l, int r, int lu = 0, int ru = nn, int ui = 1) {
    D(l)
    D(r)
    D(lu)
    D(ru)
    if(ru <= l || r <= lu || r < l || lu >= n) return 0;
    if(l <= lu && r >= ru) {
        return un[ui].s;
    }
    push(lu, ru, ui);

    int lr = query(l, r, lu, (lu+ru)/2, ui*2);
    int rr = query(l, r, (lu+ru)/2, ru, ui*2+1);

    un[ui].s = un[ui*2].s + un[ui*2+1].s;
    un[ui].s %= md;

    return (lr + rr) % md;
}

void solve() {
    int m;
    cin >> n >> m;
    cout << boolalpha;

    fs.reserve(n+7);
    int a = 0;
    int b = 1;
    for(int i = 0; i < n+7; ++i) {
        fs.push_back(a);
        int t = a;
        a = (a + b) % md;
        b = t;
    }

    D(fibbify(0, 1, 6))
    D(fibbify(0, 1, 7))


    nn = 1;
    while(nn < n) nn *= 2;
    for(int i = 0; i < n; ++i) {
        cin >> un[nn + i].s;
        un[nn + i].s %= md;
    }
    for(int i = nn-1; i > 0; --i) {
        un[i].s = (un[i*2].s + un[i*2+1].s) % md;
    }
    for(int i = 0; i < m; ++i) {
        int q, l, r;
        cin >> q >> l >> r;
        --l;
        if(q == 1) {
            goadd(l, r);
            // for(int j = 1; j < nn*2; ++j) {
            //     cout << un[j].s << ' ';
            // }
            // cout << '\n';
            // for(int j = 1; j < nn; ++j) {
            //     cout << j << ' ';
            //     if(un[j].l) {
            //         cout << un[j].a << ' ';
            //         cout << un[j].b << ' ';
            //     }
            //     cout << '\n';
            // }
        } else {
            int s = query(l, r);
            while(s < 0) s += md;
            s %= md;
            // for(int j = 1; j < nn; ++j) {
            //     cout << j << ' ';
            //     if(un[j].l) {
            //         cout << un[j].a << ' ';
            //         cout << un[j].b << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << "!! ";
            cout << s << endl;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
