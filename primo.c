/*
 * primo.c
 *
 *  Created on: 27/06/2015
 *      Author: marcelo
 */

#include <stdio.h>
#include <stdlib.h>

int primoate() {
	int numf, num, i, p, n;

	n = 0;

	printf(
			"\n--------< Imprimir Numeros Primos ate: >--------\n\nDigite um Numero: ");
	scanf("%d", &numf);

	for (num = 1; num <= numf; num++) {
		p = 0;

		i = 2;
		while (i < num) {
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
	printf("\nExistem %d Numeros Primos de 0 a %d\n", n, numf);
	numf = num = i = p = n = 0;

	return 0;
}

int verificaprimo() {
	int num, i, p;

	printf("\n--------< Verificar se Numero e Primo: >--------\n\nDigite um Numero: ");

	scanf("%d", &num);
	i = 1;
	while (++i < num) {
		printf("divisor -> %d  numero -> %d  sobra -> %d\n", i, num, num % (i));
		if ((num % (i)) == 0) {
			p = 1;
			break;
		}
	}

	if (p != 1)
		printf("Numero %d e Primo\n", num);
	else
		printf("Numero %d Nao e Primo\n", num);
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

		printf("\nDigite \"i\" para Imprimir Numeros Primo ou \"v\" para Verificar se um Numero e Primo \"e\" para Encerra a Aplicação: ");

		limparscanf(t);
		scanf("%c", &t);

		if (t == 'i' || t == 'I'){
			limparscanf(t);
			primoate();
		}
		else if (t == 'v' || t == 'V'){
			limparscanf(t);
			verificaprimo();
		}
		else if (t == '\n') //quando o usuário digitar somente enter, para evitar que execute o else de opção invalida
			t = '\n';
		else if (t == 'e' || t == 'E')
			break;
		else {
			printf("\n::::::::::::< Opis.. Opicao \"%c\" invalida!! >:::::::::::::\n",t);
		}

	}

	printf("\n............: Ate logo!! :............\n\n");

	return 0;
}

