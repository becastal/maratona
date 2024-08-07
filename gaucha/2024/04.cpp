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
	// achar o mex;
	int n; cin >> n;
	set<int> s;
    
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x > 0) s.insert(x);
	}

	int mex = 1;
	while (s.count(mex)) {
		mex++;
	}
	cout << mex << endl;

    return(0);
}
