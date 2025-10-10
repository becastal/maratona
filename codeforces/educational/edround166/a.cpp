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

bool solve()
{
	int n; cin >> n;
	string p; cin >> p;
	vector<char> nums, lets;

	for (auto c : p)
	{
		if (!((c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')))
			return false;
		else
		{
			if (c >= 'a' and c <= 'z')
				lets.push_back(c);
			else
				nums.push_back(c);
		}
	}

	for (int i = 0; i < n - 1; i++)
		if (p[i] >= 'a' and p[i] <= 'z' and !(p[i + 1] >= 'a' and p[i + 1] <= 'z'))
			return false;

	if (!lets.empty())
		for (int i = 0 ; i < lets.size() - 1; i++)
			if (lets[i] > lets[i + 1])
				return false;

	if (!nums.empty())
		for (int i = 0 ; i < nums.size() - 1; i++)
			if (nums[i] > nums[i + 1])
				return false;

	return true;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
		cout << (solve() ? "YES" : "NO") << endl;
    
    return(0);
}
