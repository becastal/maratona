#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

ll pot[30];
int solve() {
	int n, k; cin >> n >> k;

	vector<int> A;
	while (n) {
		A.push_back(n % 3);	
		n /= 3;
	}
	//reverse(all(A));

	k -= accumulate(all(A), 0);
	if (k < 0) return cout << -1 << endl, 0;

	while (A.size() > 1 and k > 1) {
		//for (int i : A) {
		//	printf("%d ", i);
		//}
		//puts("");
		//printf("k: %d\n", k);
		//puts("");

		int m = A.size();

		int quantas = min(A[m-1], k / 2);
		A[m-1] -= quantas;
		if (!A[m-1]) A.pop_back();
		k -= quantas * 2;
		A[m-2] += quantas * 3;
	}

	ll res = 0;
	for (int i = 0; i < (int)A.size(); i++) {
		res += A[i] * (pot[i+1] + i * pot[i-1]);
	}
	cout << res << endl;


	return(0);
}

int main()
{
    _;

	pot[0] = 1;
	for (int i = 1; i < 30; i++) {
		pot[i] = pot[i-1] * 3;
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

