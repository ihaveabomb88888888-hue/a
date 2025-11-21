#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    vector<ll> v;
    while(q--){
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<int> bity(30, 0);
        for (int i = 0; i < n; i++){
            for (int b = 0; b < 30; b++){
                if (v[i] & (1 << b)) {
                    bity[b]++;
                }
            }
        }
        ll wyn = 0, s, p;
        for (int i = 0; i < n; i++){
            s = 0;
            for (int b = 0; b < 30; b++){
                p = 1 << b;
                if ((v[i] & p) == 0){
                    s += bity[b] * p;
                }
                else {
                    s += (n - bity[b]) * p;
                }
            }
            wyn = max(wyn, s);
        }
        cout << wyn << endl;
    }
}
