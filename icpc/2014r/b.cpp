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

int main()
{
    _;

    int p; cin >> p;
    int soma = 0, i = 1, cont = 0;

    while (1) {
        soma = (soma + i) % (p + 1);
        cont++;
        i <<= 1;
		i %= (p + 1);
		if (!soma) break;
    }

    cout << cont << endl;
    
    return 0;
}

