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
		vector<int> v(n), pre(n), pos(n);

		for (int& vi : v)
			cin >> vi;

		pre[0] = v[0];
		for (int i = 1; i < n;i++)
			pre[i] = pre[i - 1] + v[i];

		pos[n-1] = v[n-1];
		for (int i = n - 2; i >= 0; i--)
			pos[i] = pos[i + 1] + v[i];

		pair<int, int> res = {INF, -INF};
		for (int i = 0; i < n - 1; i++)
			if (abs(pre[i] - pos[i + 1]) < abs(res.f - res.s))
				res = {min(pre[i], pos[i + 1]), max(pre[i], pos[i + 1])};

		cout << res.f << ' ' << res.s << endl;
	}
    
    return(0);
}
