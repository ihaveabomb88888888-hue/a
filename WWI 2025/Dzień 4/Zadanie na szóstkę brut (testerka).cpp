#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
ll n, x;
ll najwieksza_suma(vector<ll> arr) {
    vector<ll> pre(n + 1);
    pair<ll, ll> minpre = {0, 0};
    pair<ll, pair<ll, ll>> wynik = {0, {1, 0}};
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + arr[i];
        if (pre[i] - minpre.fi > wynik.fi) {
            wynik = {pre[i] - minpre.fi, {minpre.se + 1, i}};
        }
        if (pre[i] < minpre.fi) {
            minpre = {pre[i], i};
        }
    }
    return wynik.fi;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ll wynik = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            vector<ll> zapas = arr;
            for (int k = j; k <= i; k++) {
                zapas[k] *= x;
            }
            wynik = max(wynik, najwieksza_suma(zapas));
        }
    }
    cout << wynik << endl;
}


