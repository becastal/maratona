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

	int n; 
	while (cin >> n) {
		int N = (1 << n);
		vector<int> v(N);

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		vector<int> S(N);
		for (int i = 0; i < N; i++) {
			S[i] = 0;
			for (int j = 0; j < n; j++) {
				S[i] += v[i ^ (1 << j)];
			}
		}

		int res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < n; j++) {
				res = max(res, S[i] + S[i ^ (1 << j)]);
			}
		}

		cout << res << endl;
	}
    
    return(0);
}
