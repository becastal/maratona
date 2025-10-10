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

	// bob ganha quando o xor de tudo eh 0;
	// pra xor de tudo ser 0 ou a quantidade de cada numero eh par ou ser malandro na contagem dos numeros.
	// na real ou todos sao par ou todos sao impar. entao a cada duas tiradas da pra ganhar um ponto pra todo numero.

	int t; cin >> t;
	while (t--) {
		vector<int> v(4);
		for (int& i : v)
			cin >> i;

		int res = (v[0] & 1) == (v[1] & 1) == (v[2] & 1);
		for (int i = 0; i < 4; i++) {
			res += v[i] >> 1;
		}

		cout << res << endl;
	}
    
    return(0);
}
