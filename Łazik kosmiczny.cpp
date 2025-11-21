#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
ll nwd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return nwd(b%a, a);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll d = nwd(n, m);
    for (int i = 1; i < d; i++) {
        if (nwd(n, i) == 1 and nwd(m, d - i) == 1){
            cout << d << endl;
            for (int j = 0; j < i; ++j) cout << 'D';
            for (int j = 0; j < d - i; ++j) cout << 'P';
            return 0;

        }
    }
    cout << d + 1 << endl;
    if (nwd(n/d, m) == 1) {
        for (int i = 0; i < d; i++) cout << 'D';
        cout << 'P';
    }
    else {
        for (int i = 0; i < d; i++) cout << 'P';
        cout << 'D';
    }
}
