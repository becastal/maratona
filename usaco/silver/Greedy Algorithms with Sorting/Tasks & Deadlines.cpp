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
	vector<pair<int, int>> v(n);
 
	for (auto& [a, b] : v) cin >> a >> b;
	sort(v.begin(), v.end());
 
	ll agr = 0, total = 0;
	for (auto [a, b] : v) {
		agr += a;
		total += b - agr;
	}
	cout << total << endl;
    
    return(0);
}
