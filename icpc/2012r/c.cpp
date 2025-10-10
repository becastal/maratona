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
    int N;
    while (cin >> N) {
        vector<ll> cards(N);
        for (int i = 0; i < N; ++i) {
            cin >> cards[i];
        }

        // dp[i][j] represents the maximum points difference Alberto can achieve from subarray cards[i:j]
        vector<ll> dp(N);

        for (int i = 0; i < N; ++i) {
            dp[i] = cards[i];
        }

        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i <= N - length; ++i) {
                int j = i + length - 1;
                dp[i] = max(cards[i] - dp[i + 1], cards[j] - dp[i]);
            }
        }

        ll totalSum = accumulate(cards.begin(), cards.end(), 0LL);
        ll albertoScore = (totalSum + dp[0]) / 2;
        
        cout << albertoScore << endl;
    }
    
    return 0;
}
