a, b, c = input().split();
M = int(1e9+7)
a = int(a)
c = int(c)

def exp(x, k, M):
    if (k == 0):
        return 1

    res = exp(x*x%M, int(k/2), M)
    if (k % 2 == 1):
        return x*res%M
    else:
        return res

if (b == "+"):
    a = a % M
    c = c % M
    print((a+c)%M)
elif (b == "-"):
    a = a % M
    c = c % M
    print((a-c+M)%M)
elif (b == "*"):
    a = a % M
    c = c % M
    print(a*c%M)
elif (b == "^"):
    a = a % M
    c = c % (M-1)
    print(exp(a, c, M))
