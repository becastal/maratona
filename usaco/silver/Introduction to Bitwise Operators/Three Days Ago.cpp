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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	// para cada i olhar pra tras e ver quantas posicoes atras de mim fazem com que todos conts dos meus
	// digitos ficam todos impares.
	
	string s; cin >> s;
	vector<int> p(1 << 10, 0);
	p[0] = 1;

	ll res = 0;
	int agr = 0;
	for (char c : s) {
		agr ^= 1 << (c - '0');
		res += p[agr]++;
	}
	cout << res << endl;

    return(0);
}
