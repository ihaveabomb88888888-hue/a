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
    int n, m;
    cin >> n >> m;
    vector<int> wyniki(n), suma(m);
    vector<vector<int>> glosowanie(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> glosowanie[i][j];
            suma[j] += glosowanie[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int wynik = 0;
            for (int k = 0; k < m; k++) {
                //cout << "k, i i j " << k << " " << i << " " << j << endl;
                //cout << suma[k] << " " << glosowanie[i][k] << " " << glosowanie[j][k] << endl;
                if (suma[k] - glosowanie[i][k] - glosowanie[j][k] >= n / 2) {
                    wynik++;
                }
            }
            wyniki[i] = max(wyniki[i], wynik);
            wyniki[j] = max(wyniki[j], wynik);
        }
    }
    for (int i : wyniki) {
        cout << i << endl;
    }
}
