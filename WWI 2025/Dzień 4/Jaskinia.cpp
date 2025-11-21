#include "jaslib.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
vector<int> label(int n, int k, vector<pair<int, int>> edges) {
    vector<vector<int>> graf(n), dzie(n);
    vector<int> wa = {0}, nwa, gl(n, -1), ojc(n, -1);
    for (pair<int, int> p : edges) {
        graf[p.fi].pb(p.se);
        graf[p.se].pb(p.fi);
    }
    int li = 1;
    gl[0] = 0;
    while (wa.size() > 0) {
        for (int i : wa) {
            for (int j : graf[i]) {
                if (gl[j] == -1) {
                    gl[j] = li;
                    nwa.push_back(j);
                    ojc[j] = i;
                    dzie[i].push_back(j);
                }
            }
        }
        wa = nwa;
        nwa = {};
        li++;
    }
    vector<int> kt(n, 0), num(n);
    int ak = 0, licznik = 0;
    while (true) {
        if (kt[ak] == 0 and gl[ak] % 2 == 0) {
            num[ak] = licznik;
            licznik++;
        }
        if (kt[ak] >= dzie[ak].size() and gl[ak] % 2 == 1) {
            num[ak] = licznik;
            licznik++;
        }
        kt[ak]++;
        if (kt[ak] <= dzie[ak].size()) ak = dzie[ak][kt[ak] - 1];
        else {
            if (ak == 0) break;
            ak = ojc[ak];
        }
    }
    /*for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;*/
    return num;
}
int step(int a, int b, vector<int> s) {
    int ost = s.size() - 1;
    s.pb(1e9);
    for (int i = 0; i <= ost; i++) {
        if (s[i] == b) return b;
    }
    if (a < s[0]) { // a jest pre, reszta post
        if (b < a or b > s[ost]) {
            return s[ost];
        }
        else {
            for (int i = 0; i <= ost; i++) {
                if (s[i] > b) {
                    return s[i];
                }
            }
        }
    }
    else { // a jest post, reszta pre
        if (b < s[0] or b > a) {
            return s[0];
        }
        else {
            for (int i = 1; i <= ost; i++) {
                if (s[i] < b and s[i + 1] > b) {
                    return s[i];
                }
            }
            return s[0];
        }
    }
}
/*int main() {
    label(12, 1e9, {{0, 1}, {0, 11}, {11, 2}, {11, 3}, {11, 4}, {0, 5}, {5, 6}, {6, 7}, {2, 8}, {8, 9}, {9, 10}});
    cout << step(8, 1, {0, 2, 6, 7}) << endl;
}*/


