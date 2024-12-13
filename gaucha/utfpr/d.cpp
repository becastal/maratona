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

	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	ll soma = 0, agr = 0, res = 0;

	map<int, int> cont;
	for (int r = 0, l = 0; r < n; r++) {
		soma += v[r];
		if (cont[v[r]] & 1) agr++;
		cont[v[r]]++;

		while (soma > x) {
			if (cont[v[l]] & 1 ^ 1) agr--;
			cont[v[l]]--;
			if (!cont[v[l]]) cont.erase(v[l]);
			soma -= v[l++];
		}

		res = max(res, agr);	
	}

	cout << res << endl;
    
    return(0);
}

