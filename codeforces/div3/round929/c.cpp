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

void solve() {
	int a, b, l;
	cin >> a >> b >> l;

	int ca = 0, cb = 0;

	int la = l;
	while (la % a == 0) {
		la /= a;	
		ca++;
	}
	int lb = l;
	while (lb % b == 0) {
		lb /= b;	
		cb++;
	}

	vector<int> pa = {1}, pb = {1};
	while (ca--) {
		pa.push_back(pa.back() * a);
	}
	while (cb--) {
		pb.push_back(pb.back() * b);
	}

	set<int> res;
	for (int ai : pa) {
		for (int bi : pb) {
			if (ai * bi and l % (ai * bi) == 0) {
				res.insert(l / (ai * bi));
			}
		}
	}

	res.erase(0);
	cout << (int)res.size() << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

