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

	int n, m; cin >> n >> m;

	vector<ll> a(n), b(m);
	for (auto& ai : a)
		cin >> ai;

	for (auto& bi : b)
		cin >> bi;

	vector<ll> re;
	int r = 0, c = 0;
	for (int l = 0; l < m; l++)
	{
		while (b[l] > a[r] and r < n)
			r++, c++;
		re.push_back(c);
	}

	for (auto ri : re)
		cout << ri << ' ';
	cout << endl;
    
    return(0);
}
