#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, h, c;
    cin >> n;
    vector<pair<ll, ll>> stacje(n);
    ll akmax = 0, wynik = 0;
    for (int i = 0; i < n; i++) {
        cin >> stacje[i].fi >> stacje[i].se;
        wynik += stacje[i].se;
    }
    sort(stacje.rbegin(), stacje.rend());
    akmax = stacje.back().fi + stacje.back().se;
    while (!stacje.empty()) {
        if (akmax < stacje.back().fi) {
            wynik += stacje.back().fi - akmax;
        }
        akmax = max(akmax, stacje.back().fi + stacje.back().se);
        stacje.pop_back();
    }
    cout << wynik;
}

