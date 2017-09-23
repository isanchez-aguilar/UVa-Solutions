'''
	User: Isanchez_Aguilar
	Problem: UVA 11879 - Multiple of 17
'''
import sys

for line in sys.stdin:
	number = int(line)
	if number == 0:
		break

	if number % 17 == 0:
		print(1)
	else:
		print(0)