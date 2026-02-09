#include <bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

//mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
//
//int uniform(int l, int r){
//	uniform_int_distribution<int> uid(l, r);
//	return uid(rng);
//}
//
//int N, K;
//vector<int> V;
//
//int query(vector<int> A) {
//	int res = 0;
//	cout << "? ";
//	for (int i : A) {
//		res ^= V[i - 1];
//		cout << i << " ";
//	}
//	cout << endl;
//	return res;
//}

int query(vector<int> A) {
	cout << "? ";
	for (int i : A) {
		cout << i << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

int solve() {
	int n, k; //n = N, k = K;
	cin >> n >> k;

	if (k == 1) {
		vector<int> R(n);
		for (int i = 0; i < n; i++) {
			R[i] = query(vector<int>{i + 1});
		}
		cout << "! ";
		for (int i = 0; i < n; i++) {
			cout << R[i] << ' ';
		}
		cout << endl;
		
		return 0;
	}

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

using bigint = boost::multiprecision::cpp_int;

int solve() {

    auto I = [&]() -> bigint {
        int h, w;
        cin >> h >> w;

        bigint s = 0;
        string t;
        for (int r = 0; r < h; ++r) {
            cin >> t;
            bigint row = 0;
            for (char c : t) row = (row << 1) + (c == '#');
            s = (s << 20) + row;
        }

        if (s == 0) return 0;
        bigint low = (s & -s);
        return s / low;
    };

    bigint a = I(), b = I(), x = I();

    for (int i = 0; i < 300; ++i) {
        if ( (a | (b << i)) == x || ((a << i) | b) == x ) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

	return(0);
}

int main()
{
    _;

	

	int t = 1; //cin >> t;
	while (t--) {
	vector<int> Q(k + 1), S;
	for (int i = 1; i <= k + 1; i++) {
		S.push_back(i);
	}

	for (int i = 0; i <= k; i++) {
		auto S_ = S;
		S_.erase(find(all(S_), i + 1));
		Q[i] = query(S_);
	}

	vector<int> R(n);
	R[0] = Q[1];
	for (int i = 2; i + 1 <= k; i += 2) {
		R[0] ^= (Q[i] ^ Q[i+1]);
	}

	for (int i = 1, a = R[0]; i <= k; i++) {
		int ab = Q[i] ^ Q[i-1];
		int b = ab ^ a;
		R[i] = b;
		a = b;
	}

	int p = 0;
	for (int i = 0; i < k-1; i++) {
		p ^= R[i];
	}

	S.pop_back();
	for (int i = k + 1; i < n; i++) {
		S.pop_back();
		S.push_back(i + 1);
		R[i] = p ^ query(S);	
	}

	cout << "! ";
	for (int i = 0; i < n; i++) {
		cout << R[i] << ' ';
	}
	cout << endl;

	return(0);
}

int main()
{
    //_;

//	N = uniform(4, 1000);
//	do {
//		K = uniform(1, N - 1);
//	} while (K % 2 == 0);
//
//	V = vector<int>(N);
//	for (int i = 0; i < N; i++) {
//		V[i] = uniform(0, 1);
//	}
//	
//	printf("N: %d, K: %d\nV: [", N, K);
//	for (int i = 0; i < N; i++) {
//		printf("%d%s", V[i], (i == N-1 ? "]\n" : ", "));
//	}

	//N = 5, K = 3;
	//V = {1, 0, 1, 1, 0};

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

