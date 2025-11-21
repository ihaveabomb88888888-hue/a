#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main() {
    int n, k, m, srpo, sros, sr;
    cin >> n >> k >> m;
    vector<int> ok(m);
    vector<pair<int, int>> sekcje;
    vector<int> pier_kna2, dru_kna2, ost_kna2, post_kna2;
    for (int i = 0; i < m; i++) {
        cin >> ok[i];
    }
    sort(ok.begin(), ok.end());
    int li = 0, ak = 0, licz = 0;
    for (int i = 1; i <= n; i++) {
        if (i == ok[li]) {
            li++;
            if (ak > 0) {
                licz += ak;
                sekcje.pb({i - ak, i - 1});
                ak = 0;
            }
        }
        else {
            ak++;
        }
    }
    if (ak > 0) {
        licz += ak;
        sekcje.pb({n - ak + 1, n});
    }
    if (licz % (k - 1) != 0) {
        cout << "NIE";
        return 0;
    }
    else {
        int ak = 0;
        reverse(sekcje.begin(), sekcje.end());
        cout << "ost k na 2" << endl;
        for (pair<int, int> zakres : sekcje) {
            int pomoc = zakres.se;
            while (ost_kna2.size() < k / 2 and pomoc >= zakres.fi) {
                cout << pomoc << " ";
                ost_kna2.pb(pomoc);
                pomoc--;
                if (ost_kna2.size() == k / 2) {
                    cout << endl;
                    cout << "post k na 2" << endl;
                    sros = pomoc;
                }
            }
            while (post_kna2.size() < k / 2 and pomoc >= zakres.fi) {
                post_kna2.pb(pomoc);
                cout << pomoc << " ";
                pomoc--;
            }
        }
        cout << "pier k na 2" << endl;
        reverse(sekcje.begin(), sekcje.end());
        for (pair<int, int> zakres : sekcje) {
            int pomoc = zakres.fi;
            while (pier_kna2.size() < k / 2 and pomoc <= zakres.se) {
                pier_kna2.pb(pomoc);
                cout << pomoc << " ";
                pomoc++;
                if (pier_kna2.size() == k / 2) {
                    cout << endl;
                    cout << "dru k na 2" << endl;
                    srpo = pomoc;
                }
            }
            while (dru_kna2.size() < k / 2 and pomoc <= zakres.se) {
                dru_kna2.pb(pomoc);
                cout << pomoc << " ";
                pomoc++;
            }
        }

        // ------------------------------ znajdowanie srodkowej sejcji ----------------------------- //

        for (pair<int, int> zakres : sekcje) {
            ak += zakres.se - zakres.fi + 1;
            if (ak == licz / 2) {
                break;
            }
            else if (ak > licz / 2) {
                if (licz == k - 1) {
                    cout << "NIE";
                    return 0;
                }
                int prawo = ak - licz / 2, lewo = licz / 2 - (ak - (zakres.se - zakres.fi + 1));
                if (lewo > prawo) sr = zakres.se+1;
                else sr = zakres.fi+1;
                while (prawo > k / 2 and lewo > k / 2 + 1) {

                }
            }
        }
    }
}


