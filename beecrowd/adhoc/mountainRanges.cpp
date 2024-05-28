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
	vector<int> rgs(n);

	for (auto& ai : rgs)
		cin >> ai;

	int r = 1, p = 1;
	for (int i = 1; i < n; i++)
	{
		if (rgs[i] - rgs[i - 1] <= x)
		{
			p++;
			if (p > r) r = p;
		}
		else
			p = 1;
	}

	cout << r << endl;
    
    return(0);
}
