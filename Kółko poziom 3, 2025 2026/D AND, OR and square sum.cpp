#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    vector<int> bity(30, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int bit = 0; bit < 30; bit++) if (((1 << bit) & x) != 0) bity[bit]++;
    }
    ll wynik = 0, ak;
    for (int i = 0; i < n; i++) {
        ak = 0;
        for (int bit = 0; bit < 30; bit++) {
            if (bity[bit] > 0) {
                ak += (1 << bit);
                bity[bit]--;
            }
        }
        wynik += ak * ak;
    }
    cout << wynik;
}
