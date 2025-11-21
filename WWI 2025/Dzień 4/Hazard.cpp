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
    double z1, z2;
    vector<double> zak1(n);
    vector<double> zak2(n);
    for (int i = 0; i < n; i++) {
        cin >> z1 >> z2;
        zak1[i] = z1;
        zak2[i] = z2;
    }
    pair<double, double> sumy = {0, 0};
    double wynik = 0;
    sort(zak1.begin(), zak1.end());
    sort(zak2.begin(), zak2.end());
    while (true) {
        sumy.fi -= 1;
        sumy.se -= 1;
        if (sumy.fi < sumy.se) {
            if (zak1.empty()) {
                break;
            }
            sumy.fi += zak1.back();
            zak1.pop_back();
        }
        else {
            if (zak2.empty()) {
                break;
            }
            sumy.se += zak2.back();
            zak2.pop_back();
        }
        wynik = max(wynik, min(sumy.fi, sumy.se));
    }
    cout << fixed << setprecision(4) << wynik << endl;
}



