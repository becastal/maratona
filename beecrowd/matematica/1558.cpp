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

	vector<int> v;
	for (int i = 1; i * i <= 10000; i++) {
		v.push_back(i*i);	
	}
	
	int n;
	while (cin >> n) {
		if (n < 0) {
			cout << "NO" << endl;
			continue;
		} 

		if (!n) {
			cout << "YES" << endl;
			continue;
		} 

		int ok = 0;
		set<int> s;
		for (int i : v) {
			if (i > n) break;
			if (s.count(n-i) or n == 2*i or n == i) {
				ok = 1;
				break;
			}
			s.insert(i);
		}

		cout << (ok ? "YES" : "NO") << endl;
	}
    
    return(0);
}
