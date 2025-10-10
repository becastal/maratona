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

int n = 256;
vector<int> encode(vector<int> A) {
	vector<int> B(A);

	int l = 0, r = n;
	while (r - l > 4) {
		int p = max_element(A.begin() + l, A.begin() + r) - A.begin();
		B[p] = -1;
		
		int m = (l + r) / 2;
		if (p < m) l = m;
		else r = m;
	}

	int ok = 0;
	for (int i = l + 1; i < r and !ok; i++) {
		if (A[i] > A[i-1]) {
			B[i] = B[i-1] = -1;
			ok = 1;
		}
	}
	if (!ok) B[l] = -1, B[r-1] = -1;

	return B;
}

vector<int> decode(vector<int> B) {
	vector<int> A(B), visto(n+1, 0);

	for (int i : B) if (i > 0) visto[i] = 1;
	vector<int> falta;
	for (int i = n; i >= 1; i--) {
		if (!visto[i]) falta.push_back(i);
	}
	reverse(all(falta));

	int l = 0, r = n;
	while (r - l > 4) {
		int m = (l + r) / 2;

		int cl = count(B.begin() + l, B.begin() + m, -1),
			cr = count(B.begin() + m, B.begin() + r, -1);
		
		if (cl == 1) {
			int p = find(B.begin() + l, B.begin() + m, -1) - B.begin();
			A[p] = B[p] = falta.back();
			falta.pop_back();
			l = m;
		} else {
			assert(cr == 1);
			int p = find(B.begin() + m, B.begin() + r, -1) - B.begin();
			A[p] = B[p] = falta.back();
			falta.pop_back();
			r = m;
		}
	}

	int ok = 0;
	for (int i = l + 1; i < r and !ok; i++) {
		if (B[i] == B[i-1]) {
			A[i] = B[i] = falta.back(); falta.pop_back();
			A[i-1] = B[i-1] = falta.back(); falta.pop_back();
			ok = 1;
		}
	}

	if (!ok) {
		A[l] = B[l] = falta.back(); falta.pop_back();
		A[r-1] = B[r-1] = falta.back(); falta.pop_back();
	}

	return A;
}

int solve() {
	vector<int> P(n);
	iota(all(P), 1);

	for (int i = 0; i < 1; i++) {
		shuffle(all(P), mt19937{random_device{}()});
		vector<int> encodado = encode(P);
		vector<int> decodado = decode(encodado);
		assert(decodado == P);
		dbg(count(all(encodado), -1));
		printf("%5d: ok\n", i);
	}

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
