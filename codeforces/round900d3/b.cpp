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

const int MAX = 1e7;
	
int main()
{
    _;
    
	int t; cin >> t;
	vector<int> v = {2, 3};
	for (int i = 0; i < MAX; i++) {
		int an = v.back() + 1;		
		if (3*an % (v[i] + v[i+1]) == 0) {
			an++;
		}
		v.push_back(an);
	}

	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';	
		}
		cout << endl;
	}

    return(0);
}
