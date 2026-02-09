Your *idea* (“fix (x) and count graphs with (f(G)=x)”) is fine, but the **counting formula you wrote is not**.

The reason: the 3 Hamiltonian cycles **share edges**, so you can’t treat “4 edges of the minimum cycle sum to (x)” and “the other 2 edges sum to (K-x)” as independent the way your

```cpp
3 * stars(x-4,4) * stars(K-x-2,2)
```

does. Also, to have **min = x** you must enforce **all three cycle sums ≥ x**, and **at least one = x** (your expression enforces neither, and it also double-counts cases where multiple cycles tie).

---

## The simple trick (fits 400-rated)

Name the 6 edges:

* (a=w_{12}, b=w_{13}, c=w_{14}, d=w_{23}, e=w_{24}, f=w_{34})

The 3 Hamiltonian cycles have sums:

* (S_1 = a+d+f+c)  (1–2–3–4–1)
* (S_2 = a+e+f+b)  (1–2–4–3–1)
* (S_3 = b+d+e+c)  (1–3–2–4–1)

Now group **opposite edges**:

* (U = a+f)  (12 and 34)
* (V = b+e)  (13 and 24)
* (W = c+d)  (14 and 23)

Then:

* (S_1 = U+W)
* (S_2 = U+V)
* (S_3 = V+W)

And also (U+V+W = (a+f)+(b+e)+(c+d)=K).

So
[
f(G)=\min(U+V, U+W, V+W) = \min(K-W, K-V, K-U)=K-\max(U,V,W).
]

Now: for fixed ((U,V,W)), how many graphs realize it?

* (a+f=U) with **positive** integers → (U-1) ways
* (b+e=V) → (V-1) ways
* (c+d=W) → (W-1) ways

So multiplicity is ((U-1)(V-1)(W-1)).

Therefore the answer is just:
[
\sum_{\substack{U+V+W=K\U,V,W\ge2}} (U-1)(V-1)(W-1)\cdot (K-\max(U,V,W)).
]

That’s (O(K^2)), totally fine for (K\le 5000).

---

## Drop-in `solve()` (using your `mint`)

You don’t even need factorials/stars anymore:

```cpp
int solve() {
    int K; cin >> K;

    mint ans = 0;
    for (int U = 2; U <= K - 4; ++U) {
        for (int V = 2; V <= K - U - 2; ++V) {
            int W = K - U - V;
            if (W < 2) continue;

            int mx = max({U, V, W});
            ans += mint(U - 1) * mint(V - 1) * mint(W - 1) * mint(K - mx);
        }
    }

    cout << ans << '\n';
    return 0;
}
```

This matches brute force for small (K) (e.g., (K=6) gives 4 as expected).

---

### Why your stars approach *felt* close

You were essentially trying to count by “cycle sum = x”, but the min condition couples the cycles. The ((U,V,W)) trick decouples it completely and makes (f(G)) a one-liner: (K-\max(U,V,W)).

If you want, I can show how your “fix (x)” approach becomes workable *after* switching to ((U,V,W)), but the direct sum above is already the cleanest.

