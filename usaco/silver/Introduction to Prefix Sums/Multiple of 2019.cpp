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

	string s; cin >> s;
	int n = (int)s.size(), mod = 2019;
	vector<int> cont(mod, 0);
	cont[0] = 1;

	ll res = 0;
	int agr = 0, p = 1;
	for (int i = n-1; i >= 0; i--) {
		agr = (agr + p * (s[i] - '0') % mod) % mod;
		res += cont[agr]++;
		p = p * 10 % mod;
	}

	cout << res << endl;

    return(0);
}
