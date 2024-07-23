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

	int n, k; cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (auto& [idx, cor] : v)
		cin >> idx >> cor;

	auto vord = v;
	sort(v.begin(), v.end());
	
	bool res = true;
	for (int i = 0; i < n; i++)
	{
		res &= (v[i].s == vord[i].s);
		if (!res) break;
	}

	cout << (res ? 'Y' : 'N') << endl;
    
    return(0);
}
