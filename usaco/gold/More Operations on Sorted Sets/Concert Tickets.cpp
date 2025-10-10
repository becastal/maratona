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
 
	int n, m; cin >> n >> m;
	vector<int> h(n), t(m);
	multiset<int> M;
 
	for (int& i : h) cin >> i, M.insert(i);
	for (int& i : t) cin >> i;
 
	for (int i : t) {
		if (M.empty()) {
			cout << -1 << endl;
			continue;
		}
 
		auto it = M.upper_bound(i);
 
		if (it == M.begin()) {
			cout << -1 << endl;
			continue;
		}
		it--;
 
		cout << *it << endl;
		M.erase(M.find(*it));
	}
    
    return(0);
}
