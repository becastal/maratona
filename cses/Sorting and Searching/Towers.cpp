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
	vector<int> v(n), M;

	for (int& i : v) {
		cin >> i;
		auto it = upper_bound(M.begin(), M.end(), i);

		if (it == M.end()) M.push_back(i);
		else *it = i;
	}
	cout << M.size() << endl;
    
    return(0);
}
