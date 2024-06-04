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

	ll n, m; cin >> n >> m;
	vector<ll> h(n);
	
	for (auto& hi : h)
		cin >> hi;

	ll soma = 0, resp = 0;
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		if (soma + h[i] <= m)
			soma += h[i];
		else
		{
			while (soma + h[i] > m)
			{
				soma -= h[l];
				l++;
			}
			soma += h[i];
		}
		resp = max(soma, resp);
	}

	cout << resp << endl;

    return(0);
}
