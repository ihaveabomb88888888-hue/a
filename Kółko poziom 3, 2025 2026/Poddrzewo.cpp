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

    ll n, j1 = -1, j2 = -1, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1 and j1 == -1) j1 = i + 1;
        else if (x == 1) j2 = i + 1;
    }
    if (j2 != -1) {
        cout << 0 << endl;
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else if (j1 != -1) {
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else {
        cout << 2 << endl;
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
    }
}

