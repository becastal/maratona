s = input()

soma = s.split('+')
mult = s.split('*')
meno = s.split('-')
divi = s.split('/')

if (len(soma) == 2):
	print(int(soma[0]) + int(soma[1]))
elif (len(mult) == 2):
	print(int(mult[0]) * int(mult[1]))
elif (len(meno) == 2):
	print(int(meno[0]) - int(meno[1]))
elif (len(divi) == 2):
	print(int(divi[0]) // int(divi[1]))
