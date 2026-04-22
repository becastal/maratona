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

	ll n, s; cin >> n >> s;
	vector<ll> v(n);
	
	for (auto& vi: v)
		cin >> vi;

	ll soma = 0, l = 0, melhor = n + 1;
	for (int r = 0; r < n; r++)
	{
		soma += v[r];
		if (soma < s) continue; // r++
		
		while (soma >= s)
			soma -= v[l++];
	
		melhor = min(melhor, r - l + 2);
	}

	cout << (melhor > n ? -1 : melhor) << endl;
    
    return(0);
}
