#! /usr/bin/python

import numpy as np

lista1 = []
lista2 = []
lista3 = []

lista1.append(1)
lista2.append(1)
numerof = 2
c = 0
while len(lista2)<=999:
	j = 0

	cond = 1
	for i in lista2:
		suma = lista1[j] + i + c

		if suma < 10:
			lista3.append(suma)
			c = 0
		else:
			valor = suma%10
			lista3.append(valor)
			c = 1
			if cond == len(lista2):
				lista3.append(1)
				c = 0
		cond = cond + 1
		j = j + 1

	lista1 = []
	lista1 = lista2
	lista2 = []
	lista2 = lista3
	lista3 = []
	numerof = numerof + 1
	if len(lista1) != len(lista2):
		for ind in range(len(lista2)-len(lista1)):
			lista1.append(0)
	fibo = ' '
	if len(lista2) >= 1000:
		for x in lista2:
			fibo = str(x) + fibo
		print fibo
		print numerof
