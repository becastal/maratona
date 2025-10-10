#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), pos(n+1, -1);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i]) pos[A[i]] = i;
	}

	vector<int> prox(n, -1), ant(n, -1);
	for (int i = 0, x = -1; i < n; i++) {
		if (A[i]) x = i;
		ant[i] = x;
	}
	for (int i = n-1, x = -1; i >= 0; i--) {
		if (A[i]) x = i;
		prox[i] = x;
	}

	for (int i = 0, l = 0, r = n-1, quero = 1; i < n; i++, quero++) {
		if (A[l] == quero) {
			l++;
			continue;
		}

		if (A[r] == quero) {
			r--;
			continue;
		}

		if (pos[quero] != -1 and pos[quero] > l and pos[quero] < r 
				or (A[l] and A[r])) return cout << '*' << endl, 0;

		if (!A[l] and A[r]) {
			A[l++] = quero;
			continue;
		}

		if (A[l] and !A[r]) {
			A[r--] = quero;
			continue;
		}

		int dx = prox[l], dy = ant[r];
		if ((dx == -1 or dx > r) and (dy == -1 or dy < l)) A[l++] = quero;
		else if (dx <= r and dy >= l) {
			int x = A[dx], y = A[dy];
			if (x < y) A[l++] = quero;
			else if (y < x) A[r--] = quero;
			else {
				if ((dx - l) < (r - dy)) A[l++] = quero;
				else A[r--] = quero;
			}
		} else if (dx <= r) {
			A[l++] = quero;
		} else {
			A[r--] = quero;
		}
	}

	for (int i : A) cout << i << ' '; cout << endl;
	
	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
