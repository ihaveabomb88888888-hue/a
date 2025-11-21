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
    ll n, x;
    cin >> n >> x;
    vector<ll> dp1(n), dp2(n), dp3(n), arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i] * x;
    }
    dp1[n - 1] = arr1[n - 1];
    dp2[n - 1] = arr2[n - 1];
    dp3[n - 1] = arr1[n - 1];
    ll wynik = 0, z = 0;
    wynik = max(wynik, arr1[n - 1]);
    wynik = max(wynik, arr2[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        dp1[i] = max(z, dp1[i + 1]) + arr1[i];
        wynik = max(wynik, dp1[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        dp2[i] = max(z, max(dp1[i + 1], dp2[i + 1]))+ arr2[i];
        wynik = max(wynik, dp2[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        dp3[i] = max(z, max(dp2[i + 1], dp3[i + 1])) + arr1[i];
        wynik = max(wynik, dp3[i]);
    }
    cout << wynik;
}


