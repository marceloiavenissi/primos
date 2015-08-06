/*
 * primo.c
 *
 *  Created on: 27/06/2015
 *      Author: marcelo
 */

#include <stdio.h>
#include <stdlib.h>

int primoate() {
	int numf, numd, num, i, p, n;

	n = 0;

	printf("\n--------< Print prime numbers: >--------\n\nEnter numbers: ");
	scanf("%d", &numf);

	for (num = 1; num <= numf; num++) {
		p = 0;
		numd=num/2;

		i = 2;
		while (i < numd) {
			if ((num % (i)) == 0) {
				p = 1;
				break;
			}
			i++;
		}

		if (p == 0) {
			printf("%d\n", num);
			n++;
		}
	}
	printf("\nthere are %d prime numbers from 0 to %d\n", n, numf);
	numf = num = i = p = n = 0;

	return 0;
}

int verificaprimo() {
	int num, numd, i, p;

	printf("\n--------<check whether a number is prime: >--------\n\nEnter a number: ");

	scanf("%d", &num);
	numd=num/2;
	i = 2;
	while (i < numd) {
		printf("divider -> %d  number -> %d  remainder -> %d\n", i, num, num % (i));
		if ((num % (i)) == 0) {
			p = 1;
			break;
		}
		i++;
	}

	if (p != 1)
		printf("Number %d is prime\n", num);
	else
		printf("Number %d is not prime\n", num);
	num = i = p = 0;
	return 0;
}

void limparscanf(char c){
	// as veses o usuario colocar mais de um caracter
	// isto retira todos os carecteres guardados em ecesso,
	// inclusive o '\n', para evitar bugs como repitição de
	// linha ou erros na execução do programa.
	while (c != '\n')
		scanf("%c", &c);
}

int main() {
	char t = '\n';
	while (1 == 1) {

		printf("\nEnter \"p\" to print prime numbers or \"v\" to verify that a number is prime \"q\" to quit the application: ");

		limparscanf(t);
		scanf("%c", &t);

		if (t == 'p' || t == 'P'){
			limparscanf(t);
			primoate();
		}
		else if (t == 'v' || t == 'V'){
			limparscanf(t);
			verificaprimo();
		}
		else if (t == '\n') //quando o usuário digitar somente enter, para evitar que execute o else de opção invalida
			t = '\n';
		else if (t == 'q' || t == 'Q')
			break;
		else {
			printf("\n::::::::::::< \"%c\" is an invalid option!! >:::::::::::::\n",t);
		}

	}

	printf("\n............: See You Later!! :............\n\n");

	return 0;
}

