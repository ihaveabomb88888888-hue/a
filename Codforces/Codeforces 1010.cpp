#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, pos, odw;
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        int zera = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 0) {
                zera++;
            }
        }
        if (zera == 0) {
            cout << "1\n";
            cout << "1 " << n << "\n";
        }
        else if (v[0] == 0) {
            if (zera == (v[1] == 0) + 1) {
                cout << "2\n";
                cout << "1 2\n";
                cout << "1 " << n - 1 << "\n";
            }
            else {
                cout << "3\n";
                cout << "1 2\n";
                cout << "2 " << n - 1 << "\n";
                cout << "1 2\n";
            }
        }
        else {
            cout << "2\n";
            cout << "2 " << n << "\n";
            cout << "1 2\n";
        }
    }
}

