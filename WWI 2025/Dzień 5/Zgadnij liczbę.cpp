//#include "zgalib.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
vector<int> permutacja;
void odpowiedz(int x) {
    if (x == permutacja.back()) {
        cout << "TAK" << endl;
    }
    else {
        cout << "NIE" << endl;
    }
}
unsigned zapytaj(int i, int j) {
    return unsigned(permutacja[i] & (1 << j));
}
unsigned init() {
    int n;
    cin >> n;
    permutacja.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> permutacja[i];
    }
    unsigned x = permutacja.size();
    return x;
}
int main() {
    int n = int(init());
    int li = 0, wynik = 0;
    vector<int> wszyst(n), wszystind(n - 1);
    for (int i = 0; i < n; i++) {
        wszyst[i] = i + 1;
        if (i != n - 1) wszystind[i] = i;
    }
    while (wszyst.size() > 1) {
        vector<int> zerawsz, jedwsz, jedper, zeraper;
        for (int i : wszystind) {
            int czy = int(zapytaj(i, li));
            if (czy) jedper.pb(i);
            else zeraper.pb(i);
        }
        for (int i : wszyst) {
            if (i & (1 << li)) jedwsz.pb(i);
            else zerawsz.pb(i);
        }
        if (jedper.size() != jedwsz.size()) {
            wynik += (1 << li);
            wszyst = jedwsz;
            wszystind = jedper;
        }
        else {
            wszyst = zerawsz;
            wszystind = zeraper;
        }
        li++;
    }
    odpowiedz(wszyst[0]);
}


