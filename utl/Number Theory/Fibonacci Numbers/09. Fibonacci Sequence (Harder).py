F = {}
M = int(1e9 + 7)

def f(n):
    if n in F:
        return F[n]
    k = n // 2
    if n % 2 == 0:
        F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M
    else:
        F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M
    return F[n]

n = int(input())
n %= M * M - 1

F[0], F[1] = 1, 1

print(f(n - 1))

