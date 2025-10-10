#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 1e5+10;
vector<int> divs[MAX];
int foi[MAX];

void crivo(int n) {
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			divs[j].push_back(i);
		}
	}
}

int solve() {
	int n; cin >> n;

	memset(foi, 0, sizeof(foi));
	vector<int> R(n+1, 1);
	for (int i = 2; i <= n; i++) {
		int r = 0;
		for (int j = i; j <= n; j += i) {
			if (!foi[j]) {
				r = j;
			}
		}
		foi[r] = 1;
		R[i] = r;
	}
	for (int i = 1; i <= n; i++) {
		cout << R[i] << " \n"[i==n];
	}

	return(0);
}

int main()
{
    _;
	crivo(MAX-1);

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

