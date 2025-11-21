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
    int n;
    cin >> n;
    long double z1, z2;
    vector<ll> zak1(n);
    vector<ll> zak2(n);
    for (int i = 0; i < n; i++) {
        cin >> z1 >> z2;
        z1 *= 10000;
        z2 *= 10000;
        zak1[i] = z1;
        zak2[i] = z2;
    }
    ll wynik = 0;
    sort(zak1.rbegin(), zak1.rend());
    sort(zak2.rbegin(), zak2.rend());
    vector<ll> pre1(n + 1);
    vector<ll> pre2(n + 1);
    for (int i = 1; i <= n; i++) {
        pre1[i] = pre1[i - 1] + zak1[i - 1];
        pre2[i] = pre2[i - 1] + zak2[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            wynik = max(wynik, min(pre1[i], pre2[j]) - (i + j) * 10000);
        }
    }
    long double wyn = wynik;
    wyn /= 10000;
    cout << fixed << setprecision(4) << wyn << endl;
}



