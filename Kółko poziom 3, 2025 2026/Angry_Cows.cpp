#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second
vector<int> siano, wynl, wynp;
int n;
bool czy(int dl) {
    int i = 0;
    while (i < n and wynl[i] <= dl - 2) i++;
    i--;
    int ind = i;
    while (i < n and siano[ind] + 2 * dl >= siano[i]) i++;
    i--;
    if (wynp[i] > dl - 2) return 0;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    set<int> s;
    set<pair<int, int>> indeksy;
    int a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }
    n = s.size();
    siano.resize(n);
    wynl.resize(n);
    wynp.resize(n);
    int i = 0;
    for (int x : s) {
        x *= 2;
        siano[i] = x;
        indeksy.insert({x, i});
        i++;
    }
    wynl[0] = 0;
    ll pocz = 0, kon = 4e9, sr;

    // --------------------------- wyniki na lewo -------------------------- //
    for (int i = 1; i < n; i++) {
        pocz = 0;
        kon = 4e9;
        while (pocz < kon) {
            sr = (pocz + kon) / 2;
            auto it = indeksy.lower_bound({siano[i] - sr, -2e9});
            pair<int, int> p = *it;
            if (p.se == i or wynl[p.se] > sr - 2) {
                pocz = sr + 1;
            }
            else {
                kon = sr;
            }
        }
        wynl[i] = pocz;
        //cout << wynl[i] << " " << endl;
    }
    //cout << endl;

    // --------------------------- wyniki na prawo -------------------------- //
    wynp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        pocz = 0;
        kon = 4e9;
        while (pocz < kon) {
            sr = (pocz + kon) / 2;
            auto it = indeksy.upper_bound({siano[i] + sr, 2e9});
            it--;
            pair<int, int> p = *it;
            if (p.se == i or wynp[p.se] > sr - 2) {
                pocz = sr + 1;
            }
            else {
                kon = sr;
            }
        }
        wynp[i] = pocz;
        //cout << wynp[i] << " " << endl;
    }
    //cout << endl;

    // ------------------------------- solve -------------------------------- //
    pocz = 0;
    kon = 4e9;
    while (pocz < kon) {
        sr = (pocz + kon) / 2;
        //cout << pocz << " " << sr << " " << kon << " " << czy(sr) << endl;
        if (czy(sr)) {
            kon = sr;
        }
        else {
            pocz = sr + 1;
        }
    }
    ld wyn = pocz;
    wyn /= 2;
    cout << fixed << setprecision(1) << wyn << endl;
}
