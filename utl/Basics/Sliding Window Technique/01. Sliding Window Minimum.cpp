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
 
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int& i : v) cin >> i;
 
	map<int, int> m;
	for (int l = 0, r = 0; r < n; r++) {
		m[v[r]]++;
 
		if (r - l + 1 >= k) {
			cout << m.begin()->f << ' ';
			m[v[l]]--;
			if (!m[v[l]]) m.erase(v[l]);
			l++;
		}
	}
	cout << endl;
    
    return(0);
}
