'''
	User: Isanchez_Aguilar
	Problem: UVA 713 - Adding Reversed Numbers
'''
import sys

test_cases = int(input())

for i in range(0, test_cases):
	sum = 0
	line = input()
	numbers = line.split(' ')
	
	for j in range(0, 2):
		sum = sum + int(numbers[j][::-1])

	print(int(str(sum)[::-1]))
