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

	// b > ri - li + 1 pra todo i
	// 	-> se a == 1, entao ja suave
	// 	-> se a == b, entao [li, ri] nao pode conter nenhum multiplo de a
	//  -> da pra fazer [a, b], [2a, 2b+(b-a)], [3a, 3b+2(b-a)] ate bater

	ll n, m; cin >> n >> m;
	int a, b; cin >> a >> b;

	vector<pair<ll, ll>> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].f >> v[i].s;
		if (v[i].s - v[i].f > b) return cout << "No" << endl, 0;
	}

	if (a == b) {
		for (int i = 0; i < m; i++) {
			if ((v[i].s + 1) / a - (v[i].f) / a) return cout << "No" << endl, 0;
		}
		return cout << "Yes" << endl, 0;
	}

	vector<pair<int, int>> da;
	int i = 1;
	while (1) {
		da.emplace_back(i*a, i*b + (i-1)*(b-a));
		if (da.back().f <= da[da.size()-2].s) {
			da.back().s = INF;
			break;
		}
		i++;
	}

	ll ult = 1;
	for (int i = 0; i < m; i++) {
		ll agr = v[i].f - ult;

		int ok = 0, outro = -1;
		for (auto [l, r] : da) {
			ok |= agr >= l and agr <= r;
			if (l + b >= v[i].s and outro == -1) outro = l + b;
		}

		if (!ok and outro == -1) return cout << "No" << endl, 0;
		if (!ok and outro != -1) {
			ult = outro;
		} else {
			ult = v[i].s;
		}
	}
	cout << "Yes" << endl;
    
    return(0);
}

