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
 
	int n, q; cin >> n >> q;
	vector<int> v(n);
	vector<ll> pre(n + 1, 0);
	for (int& vi : v)
		cin >> vi;
 
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + v[i - 1];
 
	while (q--)
	{
		int a, b; cin >> a >> b; a--;
		cout << pre[b] - pre[a] << endl;
	}
    
    return(0);
}
