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
 
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
 
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());
 
	for (int& i : b) cin >> i;
	sort(b.begin(), b.end());
 
	int res = 0;
	for (int i = 0, j = 0; i < n and j < m;) {
		if (abs(a[i] - b[j]) <= k) {
			res++;
			i++, j++;
			continue;
		}
		
		if (a[i] > b[j] + k) {
			j++;
			continue;
		} else {
			i++;
			continue;
		}
	}
	cout << res << endl;
    
    return(0);
}
