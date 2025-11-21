#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a = 0, b = 0, w = -2, co;
    for (int bit = 29; bit >= 0; bit--) {
        if (w == -2) {
            cout << "? " << a << " " << b << endl;
            cin >> co;
            w = co;
            fflush(stdout);
        }
        if (w == 1) { // a > b
            cout << "? " << a + (1 << bit) << " " << b + (1 << bit) << endl;
            cin >> co;
            fflush(stdout);
            if (co == -1) {
                a += (1 << bit);
                w = -2;
            }
            else {
                cout << "? " << a + (1 << bit) << " " << b << endl;
                cin >> co;
                fflush(stdout);
                if (co == -1) {
                    a += (1 << bit);
                    b += (1 << bit);
                }
            }
        }
        else if (w == 0) {
            cout << "? " << a + (1 << bit) << " " << b << endl;
            cin >> co;
            fflush(stdout);
            if (co == -1) {
                a += (1 << bit);
                b += (1 << bit);
            }
        }
        else { // b > a
            cout << "? " << a + (1 << bit) << " " << b + (1 << bit) << endl;
            cin >> co;
            fflush(stdout);
            if (co == 1) {
                b += (1 << bit);
                w = -2;
            }
            else {
                cout << "? " << a + (1 << bit) << " " << b << endl;
                cin >> co;
                fflush(stdout);
                if (co == -1) {
                    a += (1 << bit);
                    b += (1 << bit);
                }
            }
        }
    }
    cout << "! " << a << " " << b << endl;
}
