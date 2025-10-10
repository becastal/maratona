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
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	multiset<int> da, db;
	for (int i = 1; i < n; i++) {
		da.insert(a[i]-a[i-1]);
		db.insert(b[i]-b[i-1]);
	}

	cout << (a[0] == b[0] and a.back() == b.back() and da == db ? "Yes" : "No") << endl;
    
    return(0);
}
