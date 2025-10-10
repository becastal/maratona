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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
    _;
 
	int n; cin >> n;
	ordered_set s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s.insert(i);
	}
 
	vector<int> res(n);
	for (int i = 0, pi; i < n; i++) {
		cin >> pi; pi--;
		
		res[i] = v[*s.find_by_order(pi)];
		s.erase(*s.find_by_order(pi));
	}
	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
