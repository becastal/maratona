#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() {
    _;
    
    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v) cin >> i;
 
    ordered_multiset<int> m;
 
    for (int l = 0, r = 0; r < n; r++) {
        m.insert({v[r], r});
 
        if (r - l + 1 == k) {
            int mi = m.find_by_order((k - 1) / 2)->first;
			cout << mi << ' ';
 
            m.erase({v[l], l});
            l++;
        }
    }
 
    cout << endl;
    
    return 0;
}
