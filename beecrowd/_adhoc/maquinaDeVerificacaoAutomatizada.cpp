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
	vector<int> a(5), b(5);

	for (auto& ai : a)
		cin >> ai;
    
	for (auto& bi : b)
		cin >> bi;

	for (int i = 0; i < a.size(); i++)
		if (a[i] == b[i]) return false;

	return true;
}

int main()
{
    _;

	cout << (solve() ? 'Y' : 'N') << endl;

    return(0);
}
