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
    ll n, sum = 0, wynik = 0;
    cin >> n;
    vector<int> nawiasy(n);
    stack<pair<int, int>> poprzednie;
    poprzednie.push({-1, 0});
    for (int i = 0; i < n; i++) {
        cin >> nawiasy[i];
        if (i % 2 == 0) {
            sum += nawiasy[i];
            poprzednie.top().se += nawiasy[i];
        }
        else {
            sum -= nawiasy[i];
            int za = nawiasy[i];
            int zaile = poprzednie.top().se;
            int iledob = poprzednie.top().fi;
            while (iledob != -1 and za > zaile) {
                poprzednie.pop();
                wynik += zaile;
                wynik += iledob;
                za -= zaile;
                zaile = poprzednie.top().se;
                iledob = poprzednie.top().fi;
            }
            if (za == zaile) {
                poprzednie.top().se = 0;
                wynik += za + iledob * (iledob != -1);
                if (iledob == -1) poprzednie.push({1, 0});
                else poprzednie.top().fi++;
            }
            else if (za < zaile) {
                poprzednie.top().se -= za;
                poprzednie.push({1, 0});
                wynik += za;
            }
            else if (sum < 0) {
                wynik += poprzednie.top().se;
                poprzednie.top().se = 0;
                sum = 0;
            }
        }
    }
    cout << wynik;
}

