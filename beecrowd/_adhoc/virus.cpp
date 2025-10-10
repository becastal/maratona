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

	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (auto& vi : v)
			cin >> vi;

		sort(v.begin(), v.end());
		int l = 0, r = n - 1, soma = 0;
		while (l < r)
			soma += v[r--] - v[l++];	

		cout << soma << endl;
	}
    
    return(0);
}
