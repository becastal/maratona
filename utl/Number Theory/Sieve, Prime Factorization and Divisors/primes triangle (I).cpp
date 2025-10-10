#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
//#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 1e8+10;
const int N = (MAX >> 1) + 1;
bitset<N> primo;
vector<int> primes;

void crivo(int lim) {
    primo.set();
    primo[0] = 0;
    
    for (int i = 3; i * i <= MAX; i += 2) {
        if (primo[i >> 1]) {
            for (int j = i * i; j <= MAX; j += i << 1) {
                primo[j >> 1] = 0;
            }
        }
    }
    
    primes.push_back(2);
    for (int i = 1; i < N; i++) {
        if (primo[i]) {
            primes.push_back((i << 1) | 1);
        }
    }
}

pair<int, int> pos(int ord) {
    int low = 1, high = 10000;
    int ans = high;
    while(low <= high) {
        int mid = (low + high) >> 1;
        ll sum = (ll) mid * (mid + 1) >> 1;
        if(sum >= ord) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    int row = ans;
    int prevCount = (row - 1) * row / 2;
    int col = ord - prevCount;
    return {row, col};
}

int main()
{
    _;

    crivo(MAX-1);

    int t; cin >> t;
    while (t--) {
        int x, ok = 0; 
        cin >> x;

        if (x == 2) ok = 1;
        else if (x % 2 == 0) ok = 0;
        else ok = primo[x >> 1];

        if (!ok) {
            cout << -1 << endl;
        } else {
            int ord = int(lower_bound(primes.begin(), primes.end(), x) - primes.begin()) + 1;
            auto [a, b] = pos(ord);
            cout << a << ' ' << b << endl;
        }
    }
    
    return 0;
}

