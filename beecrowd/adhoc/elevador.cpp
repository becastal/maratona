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

	int n, c; cin >> n >> c;
	vector<pair<int, int>> e(n);
	bool res = false;
	int atual = 0;
	for (auto& p : e)
	{
		cin >> p.f >> p.s;
		atual -= p.f;
		atual += p.s;
		if (atual > c) res = true;
	}

	cout << (res ? 'S' : 'N') << endl;
    
    return(0);
}
