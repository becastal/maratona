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

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<ll> cont(n + 1, 0), mx(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			int ni; cin >> ni;
			if (ni <= n) cont[ni]++;
		}
		
		for (int i = 1;i <= n; i++)
			for (int j = i; j <= n; j += i)
				mx[j] += cont[i];
		
		cout << *max_element(mx.begin(), mx.end()) << endl;
	}
    
    return(0);
}
