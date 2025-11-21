#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string w1, w2;
    cin >> w1;
    cin >> w2;
    int n = w1.size(), m = w2.size();
    vector<vector<int>> dyn(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w2[j - 1] == w1[i - 1]) {
                dyn[i][j] = dyn[i - 1][j - 1] + 1;
            }
            else {
                dyn[i][j] = max(dyn[i - 1][j], dyn[i][j - 1]);
            }
        }
    }
    /*cout << "dyn" << endl;
    for (vector<int> v : dyn) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }*/
    vector<int> wynik;
    int i = n, j = m;
    while (i > 1 or j > 1) {
        if (w1[i - 1] == w2[j - 1]) {
            wynik.push_back(w1[i - 1]);
            j--;
            i--;
            if (j < 1 or i < 1) {
                break;
            }
        }
        else if (j == 1 or i == 1) {
            if (j == 1) {
                i--;
            }
            else {
                j--;
            }
        }
        else if (dyn[i - 1][j] > dyn[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(wynik.begin(), wynik.end());
    for (char c : wynik) {
        cout << c << " ";
    }
}

