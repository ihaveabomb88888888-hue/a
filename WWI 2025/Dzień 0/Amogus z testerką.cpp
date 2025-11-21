//#include "amolib.h"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, k, impo, glli = 0;
vector<int> symak;
vector<int> sympo;
void ruch() {
    for (int i = 0; i < n; i++) {
        if (i != impo) {
            symak[(i + n - 1) % n] += sympo[i] / 2;
            symak[(i + 1) % n] += sympo[i] / 2 + sympo[i] % 2;
        }
        else {
            symak[(i + 1) % n] += sympo[i];
        }
    }
    sympo = symak;
    for (int i = 0; i < n; i++) symak[i] = 0;
}
void Zacznij(int& n, int& k) {
    cin >> n >> k >> impo;
    impo--;
}
void Odpowiedz(int ak) {
    if (ak - 1 == impo) {
        cout << "TAK";
    }
    else {
        cout << "NIE";
    }
}
int Pytaj(int ak) {
    glli++;
    if (ak < 1 or ak > n or glli >= 1000) {
        cout << "---------------------------------------------------zle---------------------------------------------------" << endl;
        return 0;
    }
    else if (ak > n) {
        ruch();
        return k;
    }
    else {
        int wyn = sympo[ak - 1];
        ruch();
        return wyn;
    }
}
int main() {
    Zacznij(n, k);
    for (int i = 0; i < n; i++) {
        sympo.pb(k);
        symak.pb(0);
    }
    int ak = 1, li = 1, odp = Pytaj(1);
    while (odp == k and ak <= n) {
        odp = Pytaj(ak);
        cout << "Pytamy o " << ak << " odpowiedz to " << odp << endl;
        if (odp != k) {
            break;
        }
        ak += li;
        li++;
    }
    if (odp > k and ak == 1) {
        Odpowiedz(n);
        return 0;
    }
    if (odp > k and ak == 2) {
        Odpowiedz(1);
        return 0;
    }
    while (odp < k) {
        ak++;
        odp = Pytaj(ak);
        cout << "Pytamy o " << ak << " odpowiedz to " << odp << endl;
    }
    Odpowiedz(ak);
}
