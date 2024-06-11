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
	int c = 1, t = 0;
	for (int i = 0; i < n; i++)
	{
		t += c;
		if (v[i + 1] != v[i]) c++;
	}

	cout << t << endl;
    
    return(0);
}
