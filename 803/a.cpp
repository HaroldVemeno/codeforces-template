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
    int n; cin >> n;
    int l = 0;
    int r = n;
    while(l + 1 != r) {
        int m = (l + r)/2;
        cout << "? " << l + 1 << ' ' << m << endl;
        int cnt = 0;
        for(int i = l; i < m; ++i) {
            int x; cin >> x;
            --x;
            if(l <= x && x < m) ++cnt;
        }
        if(cnt % 2 == 1) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << "! " << l+1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;
    while(tests-- > 0) {
        solve();
    }

}



// void solve() {
//     int n; cin >> n;
//     vector<int> as;

//     for(int i = 0; i < n; ++i) {
//         int temp; cin >> temp;
//         as.push_back(temp);
//     }
//     set<int> st{all(as)};
//     sort(all(as));


//     if(st.find(as[n-1] + as[n-2] + as[n-3]) == st.end()) {
//         cout << "NO" << '\n';
//         return;
//     }
//     if(st.find(as[0] + as[1] + as[2]) == st.end()) {
//         cout << "NO" << '\n';
//         return;
//     }
//     if(st.find(as[0] + as[1] + as[n-1]) == st.end()) {
//         cout << "NO" << '\n';
//         return;
//     }
//     if(st.find(as[0] + as[n-2] + as[n-1]) == st.end()) {
//         cout << "NO" << '\n';
//         return;
//     }



//     else cout << "YES" << '\n';


// }
