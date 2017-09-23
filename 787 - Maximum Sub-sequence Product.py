'''
	User: Isanchez_Aguilar
	Problem: UVA 787 - Maximum Sub-sequence Product
'''
import sys

for line in sys.stdin:
	line = line[0:len(line) - 1]

	numbers = line.split(' ')
	numbers = numbers[0:len(numbers) - 1]
	
	maxProduct = -999999
	numbers_length = len(numbers)
	
	for i in range(numbers_length):
		currentProduct = int(numbers[i])
		maxProduct = max(currentProduct, maxProduct)
		for j in range(i + 1, numbers_length):
			product = currentProduct * int(numbers[j])
			maxProduct = max(maxProduct, product)
			currentProduct = product

	print(maxProduct)