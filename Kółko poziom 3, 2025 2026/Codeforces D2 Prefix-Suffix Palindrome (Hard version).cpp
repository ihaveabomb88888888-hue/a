#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
ll mod  = 998244353;
ll pod  = 257;
ll mod2 = 1000000007;
ll pod2 = 257;
ll mod3 = 1000000009;
ll pod3 = 137;
int n;
vector<ll> czyt(vector<ll>& hasz, vector<ll>& potegi, vector<ll>& hasz2, vector<ll>& potegi2, vector<ll>& hasz3, vector<ll>& potegi3, ll a, ll b) {
    ll hash1 = (hasz[b] - (hasz[a] * potegi[b - a] % mod) + mod) % mod;
    ll hash2 = (hasz2[b] - (hasz2[a] * potegi2[b - a] % mod2) + mod2) % mod2;
    ll hash3 = (hasz3[b] - (hasz3[a] * potegi3[b - a] % mod3) + mod3) % mod3;
    return {hash1, hash2, hash3};
}
vector<ll> czytodw(vector<ll>& hasz, vector<ll>& potegi, vector<ll>& hasz2, vector<ll>& potegi2, vector<ll>& hasz3, vector<ll>& potegi3, ll a, ll b) {
    ll A = n - b;
    ll B = n - a;
    ll hash1 = (hasz[B] - (hasz[A] * potegi[B - A] % mod) + mod) % mod;
    ll hash2 = (hasz2[B] - (hasz2[A] * potegi2[B - A] % mod2) + mod2) % mod2;
    ll hash3 = (hasz3[B] - (hasz3[A] * potegi3[B - A] % mod3) + mod3) % mod3;
    return {hash1, hash2, hash3};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        n = s.size();

        vector<ll> hasz  = {0}, haszodw = {0}, potegi  = {1};
        vector<ll> hasz2 = {0}, haszodw2 = {0}, potegi2 = {1};
        vector<ll> hasz3 = {0}, haszodw3 = {0}, potegi3 = {1};
        vector<ll> haszpod, haszodwpod;

        for (int i = 0; i < n; i++) {
            hasz.push_back((hasz.back() * pod + (s[i] - 'a' + 1)) % mod);
            haszodw.push_back((haszodw.back() * pod + (s[n - i - 1] - 'a' + 1)) % mod);
            potegi.push_back((potegi.back() * pod) % mod);

            hasz2.push_back((hasz2.back() * pod2 + (s[i] - 'a' + 1)) % mod2);
            haszodw2.push_back((haszodw2.back() * pod2 + (s[n - i - 1] - 'a' + 1)) % mod2);
            potegi2.push_back((potegi2.back() * pod2) % mod2);

            hasz3.push_back((hasz3.back() * pod3 + (s[i] - 'a' + 1)) % mod3);
            haszodw3.push_back((haszodw3.back() * pod3 + (s[n - i - 1] - 'a' + 1)) % mod3);
            potegi3.push_back((potegi3.back() * pod3) % mod3);
        }


        int l = 0, r = n - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                break;
            }
        }
        l--;
        r++;
        int nl = l, nr = r;
        for (int i = l + 1; i < r; i++) {
            haszpod = czyt(hasz, potegi, hasz2, potegi2, hasz3, potegi3, l + 1, i);
            haszodwpod = czytodw(haszodw, potegi, haszodw2, potegi2, haszodw3, potegi3, l + 1, i);
            if (haszpod[0] == haszodwpod[0] and haszpod[1] == haszodwpod[1] and haszpod[2] == haszodwpod[2]) {
                nl = i;
            }
        }
        for (int i = r - 1; i > l; i--) {
            haszpod = czyt(hasz, potegi, hasz2, potegi2, hasz3, potegi3, i, r);
            haszodwpod = czytodw(haszodw, potegi, haszodw2, potegi2, haszodw3, potegi3, i, r);
            if (haszpod[0] == haszodwpod[0] and haszpod[1] == haszodwpod[1] and haszpod[2] == haszodwpod[2]) {
                nr = i;
            }
        }
        if (nl > n - nr) {
            for (int i = 0; i < nl; i++) cout << s[i];
            for (int i = r; i < n; i++) cout << s[i];
        }
        else {
            for (int i = 0; i <= l; i++) cout << s[i];
            for (int i = nr; i < n; i++) cout << s[i];
        }
        cout << endl;
    }
}
