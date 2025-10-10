#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const double pi = acos(-1);
typedef complex<double> cmpl;

vector<cmpl> fft(vector<cmpl> P) {
	int n = P.size();
	if (n == 1) return P;

	vector<cmpl> A(n/2), B(n/2);
	for (int i = 0; i < n/2; i++) {
		A[i] = P[2*i];
		B[i] = P[2*i+1];
	}

	vector<cmpl> Pp(n), Ap = fft(A), Bp = fft(B);
	for (int i = 0; i < n/2; i++) {
		double alf = 2.0 * pi * i / n;
		cmpl wi(cos(alf), sin(alf));
		Pp[i] = Ap[i] + wi * Bp[i];
		Pp[i + n/2] = Ap[i] - wi * Bp[i];
	}
	return Pp;
};

vector<cmpl> ifft(vector<cmpl> Pp) {
	int n = Pp.size();
	if (n == 1) return Pp;

	vector<cmpl> Ap(n/2), Bp(n/2);
	for (int i = 0; i < n/2; i++) {
		double alf = 2.0 * pi * i / n;
		cmpl wi(cos(alf), sin(alf));
		Ap[i] = (Pp[i] + Pp[i + n/2]) / 2.0;
		Bp[i] = (Pp[i] - Pp[i + n/2]) / (2.0 * wi);
	}

	vector<cmpl> P(n), A = ifft(Ap), B = ifft(Bp);
	for (int i = 0; i < n/2; i++) {
		P[2*i] = A[i];	
		P[2*i+1] = B[i];	
	}
	return P;
};

vector<ll> multiply(vector<ll> A, vector<ll> B) {
	int n = 1, m = A.size() + B.size() - 1;
	while (n < m) {
		n <<= 1;
	}

	vector<cmpl> A_(n, 0), B_(n, 0);
	for (int i = 0; i < A.size(); i++) {
		A_[i] = A[i];
	}
	for (int i = 0; i < B.size(); i++) {
		B_[i] = B[i];
	}

	vector<cmpl> Ap = fft(A_), Bp = fft(B_), Cp(n, 0);
	for (int i = 0; i < n; i++) {
		Cp[i] = Ap[i] * Bp[i];
	}
	vector<cmpl> C_ = ifft(Cp);

	vector<ll> C(m);
	for (int i = 0; i < m; i++) {
		C[i] = round(C_[i].real());
	}
	return C;
};

int solve() {
	int n; cin >> n;
	vector<ll> A(n);
	for (ll& i : A) cin >> i;

	int m; cin >> m;
	vector<ll> B(m);
	for (ll& i : B) cin >> i;

	vector<ll> C = multiply(A, B);
	for (ll i : C) cout << i << ' '; cout << endl;

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
