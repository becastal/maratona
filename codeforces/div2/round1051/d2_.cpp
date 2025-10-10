#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'007;

struct Mint {
    int v;
    Mint(long long x=0){ x%=MOD; if(x<0) x+=MOD; v=int(x); }
    Mint& operator+=(const Mint& o){ v+=o.v; if(v>=MOD) v-=MOD; return *this; }
    friend Mint operator+(Mint a, const Mint& b){ return a+=b; }
};

struct Fenwick {
    int N; vector<Mint> bit;
    Fenwick(): N(0) {}
    Fenwick(int n): N(n), bit(n+1) {}
    void add(int idx, Mint val){ for(; idx<=N; idx+=idx&-idx) bit[idx]+=val; }
    Mint sum(int idx) const { Mint r=0; for(; idx>0; idx-=idx&-idx) r = r + bit[idx]; return r; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    while(T--){
        int n; cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;

        // Column Fenwicks: for each b in [0..n], store over a in [0..b] -> index (a+1), size b+1
        vector<Fenwick> col(n+1);
        for(int b=0; b<=n; ++b) col[b] = Fenwick(b+1);

        // Row Fenwicks: for each a in [0..n], store over b in [a..n] -> index (b-a+1), size (n-a+1)
        vector<Fenwick> row(n+1);
        for(int aa=0; aa<=n; ++aa) row[aa] = Fenwick(n - aa + 1);

        auto add_cell = [&](int L, int R, Mint val){
            // dp[L][R] += val, with 0<=L<=R<=n
            col[R].add(L+1, val);
            row[L].add((R - L + 1), val);
        };
        auto col_pref = [&](int R, int Amax)->Mint{
            // sum_{a=0..Amax} dp[a][R], require Amax<=R
            return col[R].sum(Amax + 1);
        };
        auto row_pref = [&](int L, int Rmax)->Mint{
            // sum_{b=L..Rmax} dp[L][b], require Rmax>=L
            return row[L].sum(Rmax - L + 1);
        };

        // dp[0][0] = 1 (empty subsequence)
        add_cell(0, 0, 1);

        for(int x : a){
            // Snapshot BEFORE any updates for this x.

            // Case 1: b > x  -> (a,b) -> (x,b)  with a in [0..x]
            vector<Mint> Scol; Scol.reserve(n - x);
            for(int b = x+1; b <= n; ++b) Scol.push_back(col_pref(b, x));

            // Case 2: b <= x -> (a,b) -> (a,x)  with b in [a..x], i.e. row-prefix up to x for each a<=x
            vector<Mint> Srow(x+1);
            for(int L=0; L<=x; ++L) Srow[L] = row_pref(L, x);

            // Apply updates (using snapshots)
            // Case 1:
            for(int b = x+1, i=0; b <= n; ++b, ++i){
                if(Scol[i].v) add_cell(x, b, Scol[i]);
            }
            // Case 2:
            for(int L=0; L<=x; ++L){
                if(Srow[L].v) add_cell(L, x, Srow[L]);
            }
            // "skip" is implicit: we never erase old states.
        }

        // Answer = sum over all dp[L][R] = sum_R col_pref(R, R)
        Mint ans = 0;
        for(int R=0; R<=n; ++R) ans += col_pref(R, R);
        cout << ans.v << '\n';
    }
    return 0;
}
