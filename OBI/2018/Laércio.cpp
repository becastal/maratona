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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n), vi;
		for (int& i : v) { 
			cin >> i;
			if (i & 1) {
				vi.push_back(i);
			}
		}
		
		n = vi.size();
		sort(vi.rbegin(), vi.rend());
		vector<int> res(n);
		for (int i = 0, j = 0; i < n; i += 2) {
			res[i] = vi[j++];
		}
		for (int i = 1, j = n - 1; i < n; i += 2) {
			res[i] = vi[j--];
		}
		
		for (int i = 0; i < n; i++) {
			cout << (i ? " " : "") << res[i];
		}
		cout << endl;
	}
    
    return(0);
}
