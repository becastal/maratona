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

	vector<ll> r;
	int ai = 0, bi = 0;
	while (ai < a.size() or bi < b.size())
	{
		if ((ai < a.size() and a[ai] <= b[bi]) or bi >= b.size())
		{
			r.push_back(a[ai]);
			ai++;
		}
		else if ((bi < b.size() and b[bi] < a[ai]) or ai >= a.size())
		{
			r.push_back(b[bi]);
			bi++;
		}
	}

	for (auto ri : r)
		cout << ri << ' ';
	cout << endl;
    
    return(0);
}

