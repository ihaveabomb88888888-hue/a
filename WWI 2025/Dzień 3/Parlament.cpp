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
    int n, m, a;
    cin >> n >> m;
    vector<int> suma(m);
    vector<vector<int>> glosowanie(n, vector<int>(m));
    vector<pair<int, int>> nadmaski(1 << m, {-1, -1});
    for (int i = 0; i < n; i++) {
        int li = 0;
        for (int j = 0; j < m; j++) {
            cin >> a;
            glosowanie[i][j] = (a == 0);
            suma[j] += a;
            li += (1 << j) * (a == 0);
        }
        if (nadmaski[li].fi == -1) nadmaski[li] = {i, -1};
        else nadmaski[li].se = i;
        //cout << li << " " << nadmaski[li].fi << " " << nadmaski[li].se << endl;
    }
    for (int bit = 0; bit < m; bit++) {
        for (int i = (1 << m) - 1; i >= 0; i--) {
            int prze = 1 << bit;
            if (!(prze & i)) {
                if (nadmaski[i].fi == -1) {
                    nadmaski[i] = nadmaski[i^prze];
                } else if (nadmaski[i ^ prze].fi != nadmaski[i].fi and nadmaski[i ^ prze].fi != -1) nadmaski[i].se = nadmaski[i ^ prze].fi;
                else if (nadmaski[i ^ prze].se != -1 and nadmaski[i ^ prze].se != nadmaski[i].fi) nadmaski[i].se = nadmaski[i ^ prze].se;
            }
        }
    }
    vector<pair<pair<int, int>, pair<int, int>>> podmaski(1<<m, {{1e9, 1e9}, {1e9, 1e9}});
    pair<pair<int, int>, pair<int, int>> p1;
    pair<pair<int, int>, pair<int, int>> p2;
    vector<pair<int, int>> pary;
    vector<pair<int, int>> pary2;
    for (int i = 0; i < (1<<m); i++) {
        if (nadmaski[i].fi != -1) podmaski[i].fi = {0, nadmaski[i].fi};
        if (nadmaski[i].se != -1) podmaski[i].se = {0, nadmaski[i].se};
    }
    for (int bit = 0; bit < m; bit++) {
        for (int i = 0; i < (1<<m); i++) {
            int prze = 1<<bit;
            if (i & prze) {
                p2 = podmaski[i^prze];
                p1 = podmaski[i];
                pary = {p1.fi, p1.se, {p2.fi.fi + 1, p2.fi.se}, {p2.se.fi + 1, p2.se.se}};
                sort(pary.begin(), pary.end());
                pary2.clear();
                pary2.pb(pary[0]);
                int li = 1;
                while (pary2.size() < 2) {
                    if (pary2[0].se != pary[li].se or pary[li].fi >= 1e9) {
                        pary2.pb(pary[li]);
                        break;
                    }
                    li++;
                }
                podmaski[i] = {pary2[0], pary2[1]};
            }
        }
    }
    /*cout << "nadmaski" << endl;
    for (int i = 0; i < (1 << m); i++) {
        cout << nadmaski[i].fi << " " << nadmaski[i].se << " " << i << endl;
    }
    cout << "podmaski" << endl;
    for (int i = 0; i < (1 << m); i++) {
        cout << podmaski[i].fi.fi << " " << podmaski[i].fi.se << " " << podmaski[i].se.fi << " " << podmaski[i].se.se << " " << i << endl;
    }*/
    int kryt, wynik, zmiana;
    for (int i = 0; i < n; i++) {
        kryt = 0;
        wynik = 0;
        for (int j = 0; j < m; j++) {
            zmiana = -(!glosowanie[i][j]);
            if (suma[j] + zmiana > n/2) {
                wynik++;
            }
            else if (suma[j] + zmiana == n/2) {
                wynik++;
                kryt += (1 << j);
            }
        }
        //cout << kryt << endl;
        if ((nadmaski[kryt].fi != -1 and nadmaski[kryt].fi != i) or (nadmaski[kryt].se != -1 and nadmaski[kryt].se != i)) {
            cout << wynik << endl;
        }
        else if (podmaski[kryt].fi.se != i) {
            cout << wynik - podmaski[kryt].fi.fi << endl;
        }
        else {
            cout << wynik - podmaski[kryt].se.fi << endl;
        }

    }
}


