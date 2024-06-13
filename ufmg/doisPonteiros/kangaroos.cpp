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

	int n; cin >> n;
	vector<int> v(n);

	for (auto& vi : v)
		cin >> vi;

	sort(v.begin(), v.end());

	int l = 0, r = n / 2;
	int tirou = 0;

	while (l < n / 2 and r < n)
	{
		if (v[l] * 2 <= v[r])
		{
			l++, r++;
			tirou++;
		}
		else
			r++;
	}

	cout << n - tirou << endl;
    
    return(0);
}
