#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main() {
    int n, d, w, h, s, akmax = 0, po, maxn = 100000001;
    cin >> n >> d;
    int wynik = n;
    vector<int> dyn(1e8 + 3, 0);
    vector<pair<int, pair<int, int>>> smerfy(n, {0, {0, 0}});
    for (int i = 0; i < n; i++) {
        cin >> s >> w >> h;
        smerfy[i].fi = w;
        smerfy[i].se.fi = h;
        smerfy[i].se.se = s;
    }
    sort(smerfy.rbegin(), smerfy.rend());
    po = smerfy[0].fi;
    for (pair<int, pair<int, int>> smerf : smerfy) {
        for (int i = min(100000001, 2 * po - 1); i >= 2 * smerf.fi; i--) {
            akmax = max(akmax, dyn[i]);
        }
        int wyskoczyl = 0;
        for (int i = smerf.fi + 1; i <= smerf.fi * 2; i++) {
            if (i > 1e8 + 2) {
                dyn[i - smerf.fi] = min(maxn + 1, max(dyn[i - smerf.fi], smerf.se.fi));
            }
            else {
                dyn[i - smerf.fi] = min(maxn + 1, max(dyn[i - smerf.fi], dyn[i] + smerf.se.fi));
                if (dyn[i] + smerf.se.se > d) {
                    wyskoczyl = 1;
                }
            }
        }
        dyn[smerf.fi] = min(maxn + 1, max(dyn[smerf.fi], akmax + smerf.se.fi));
        if (akmax + smerf.se.se > d) {
            wyskoczyl = 1;
        }
        if (wyskoczyl) {
            wynik--;
        }
        po = smerf.fi;
    }
    cout << wynik << endl;
}
