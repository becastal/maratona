def crivo(lim):
    divi = [0] * (lim + 1)
    primes = []

    divi[1] = 1
    for i in range(2, lim + 1):
        if divi[i] == 0:
            divi[i] = i
            primes.append(i)
        for j in primes:
            if j > divi[i] or i * j > lim:
                break
            divi[i * j] = j

    return primes

MAX = int(2e6 + 10)
primes = crivo(MAX-1)

n = int(input())
res = 0
for i in range(len(primes)):
	a1 = primes[i] * primes[i]
	if (primes[i] ** 8 <= n):
		res += 1;
	
	for j in range(i+1, len(primes)):
		a2 = primes[j] * primes[j]
		
		if (a1 * a2 > n):
			break
		
		res += 1

print(res)
