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

char solve()
{

	vector<int> v(5);
	for (auto& vi : v)
		cin >> vi;

	bool cres = true;
	for (int i = 0; i < 4; i++)
		if (v[i] > v[i + 1])
			cres = false;
	if (cres) return 'C';

	bool dcres = true;
	for (int i = 0; i < 4; i++)
		if (v[i] < v[i + 1])
			dcres = false;
	if (dcres) return 'D';

	return 'N';
}

int main()
{
    _;

	cout << solve() << endl;

    return(0);
}
