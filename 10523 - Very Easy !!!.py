#
#	User: Isanchez_Aguilar
#	Problem: UVA 10523 - Very Easy !!!
from sys import stdin

for line in stdin:
	numbers = line.split(" ")

	N = int(numbers[0])
	A = int(numbers[1])
	p = 0
	q = 0
	if A == 0:
		print("0")
	else:
		if A != 1:
			# (A * ((N * (A - 1) - 1) A^N + 1))
			p = (A * ((N * (A - 1) - 1) * A ** N + 1))
			q = (A - 1) ** 2
		else:
			p = N * (N + 1)
			q = 2
		print(p // q)