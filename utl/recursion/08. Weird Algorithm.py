def f(a):
	print(a, end=' ')
	if (a == 1):
		return

	if (a % 2 == 0):
		f(a // 2)
	else:
		f(3 * a + 1)

n = int(input())
f(n)
print()
