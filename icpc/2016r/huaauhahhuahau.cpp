#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

bool ehPalindromo(string s)
{
    int j = 0, k = s.size() - 1;
    while (j < k)
    {
        if (s[j] != s[k])
            return false;
        j++, k--;
    }

    return true;
}

int main()
{
    string risada; cin >> risada;
    string vogais = "";

    for (int i = 0; i < risada.size(); i++)
        if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u')
            vogais += risada[i];

    int j = 0, k = vogais.size() - 1;
    cout << (ehPalindromo(vogais) ? "S" : "N") << endl;
    return 0;
}
