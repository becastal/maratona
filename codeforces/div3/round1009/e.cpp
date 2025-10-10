#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	srand(time(NULL));
	int n; cin >> n;
	if (n == -1) exit(0);
	if (n == 3) {
		cout << "! 1 2 3" << endl;
		return;
	}

	int agr = 0;
	vector<int> v = {1, 2, 3};

	auto query = [&]() {
		cout << "? " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
		int x; cin >> x;
		if (x == -1) exit(0);
		return x;
	};

	for (int ii = 0; ii < 75; ii++) {
		int qi = query();

		if (!qi) {
			cout << "! " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;	
			return;
		}

		v[rand() % 3] = qi;
		//agr = (agr + 1) % 3;
	}

	cout << "! " << v[0] << ' ' << v[1] << ' ' << v[2] << endl;	
}

int main()
{
    //_;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
