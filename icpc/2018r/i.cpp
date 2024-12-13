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
typedef bitset<1001> bs;

int main()
{
    _;

	int n, m; cin >> n >> m;
	bs agr;
	int l; cin >> l;
	for (int i = 0, x; i < l; i++) {
		cin >> x;
		agr[x] = 1;
	}

	vector<bs> it(n);
	for (int i = 0; i < n; i++) {
		int l; cin >> l;
		for (int j = 0, x; j < l; j++) {
			cin >> x;
			it[i][x] = 1;
		}
	}

	int cont = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < it.size(); j++) {
			if (agr.count() == 0) return cout << cont << endl, 0;
			agr ^= it[j];
			cont++;
		}
	}
	cout << -1 << endl;
    
    return(0);
}
