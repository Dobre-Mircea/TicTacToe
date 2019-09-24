#include <stdio.h>
#include <stdlib.h>

void drawMatrix(int matrix[3][3]) {
	int matrixPozitii[3][3] = {
		{7, 8, 9},
		{4, 5, 6},
		{1, 2, 3}
	};
	char matrixX[5][10] = {
		"*       *",
		"  *   *  ",
		"    *    ",
		"  *   *  ",
		"*       *"
	};

	char matrix0[5][10] = {
		" * * * * ",
		" *     * ",
		" *     * ",
		" *     * ",
		" * * * * "
	};

	int i, j, k, l;
	for (i = 0; i < 3; i++) {
		/*
			i-ul indexeaza o linie mare din jocul X si O
		*/
		if (i != 0) {
			printf("=============================\n");
		}
		/*
			o linie indexata de i contine alte 5 linii
		*/
		for (j = 0; j < 5; j++) {
			/*
				o linie j contine o linie din prima casuta 
				, o linia din a doua si o linie din a 3-a
			*/
			for (k = 0; k < 3; k++) {
				if (matrix[i][k] == 0) {
					if (j == 2) {
						printf("    %d    ", matrixPozitii[i][k]);
					} else {
						printf("         ");
					}
				}
				else if (matrix[i][k] == 1)
					printf("%s", matrixX[j]);
				else
					printf("%s", matrix0[j]);

				if (k != 2) {
					printf("|");
				} else {
					printf("\n");
				}
			}
		}
	}
}

void drawRules() {
	printf("\n\n");
	printf("=============================\n");
	printf("====Bine ai venit in jocul X si 0\n");
	printf("====Pentru a selecta o anumita celula foloseste:\n");
	printf("==== 7 | 8 | 9\n");
	printf("-------|---|--\n");
	printf("==== 4 | 5 | 6\n");
	printf("-------|---|--\n");
	printf("==== 1 | 2 | 3\n");
	printf("=============================\n");
}

int checkGame(int matrix[3][3]) {
	//////////////////////SE VERIFICA DACA A CASTIGAT CINEVA PE LINII
	if (matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2]) {
		if (matrix[0][0] == 1) {
			return 10; //10 va fi daca a castigat X-ul
		} else if (matrix[0][0] == 2)
			return 20; //20 va fi daca a castigat 0-ul
	}

	if (matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2]) {
		if (matrix[1][0] == 1) {
			return 10; //10 va fi daca a castigat X-ul
		} else if (matrix[1][0] == 2)
			return 20; //20 va fi daca a castigat 0-ul
	}

	if (matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2]) {
		if (matrix[2][0] == 1) {
			return 10; //10 va fi daca a castigat X-ul
		} else if (matrix[2][0] == 2)
			return 20; //20 va fi daca a castigat 0-ul
	}
	////////////////////SE VERIFICA DACA A CASTIGAT CINEVA PE COLOANE
	if (matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0]) {
		if (matrix[0][0] == 1) {
			return 10; //10 va fi daca a castigat X-ul
		} else if (matrix[0][0] == 2)
			return 20; //20 va fi daca a castigat 0-ul
	}

	if (matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1]) {
		if (matrix[0][1] == 1) {
			return 10; //10 va fi daca a castigat X-ul
		} else if (matrix[0][1] == 2)
			return 20; //20 va fi daca a castigat 0-ul
	}

	if (matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2]) {
		if (matrix[0][2] == 1) {
			return 10; //10 va fi daca a castigat X-ul
		} else if (matrix[0][2] == 2)
			return 20; //20 va fi daca a castigat 0-ul
	}
	////////////////////SE VERIFICA DACA A CASTIGAT CINEVA PE DIAGONALE

	if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) {
		if (matrix[0][0] == 1) {
			return 10; //10 va fi daca a castigat X-ul
		} else if (matrix[0][0] == 2)
			return 20; //20 va fi daca a castigat 0-ul
	}

	if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]) {
		if (matrix[0][2] == 1) {
			return 10; //10 va fi daca a castigat X-ul
		} else if (matrix[0][2] == 2)
			return 20; //20 va fi daca a castigat 0-ul
	}

	int emptyCount = 0, i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (matrix[i][j] == 0) {
				emptyCount++;
			}
		}
	}
	if (emptyCount == 0) {
		return 1; //Nu exista spatii libere
	}
	return 0;
}

int isEmpty(int matrix[3][3], int move) {
	if (move == 1) {
		if (matrix[2][0] == 0) {
			return 1;
		}
	}
	if (move == 2) {
		if (matrix[2][1] == 0) {
			return 1;
		}
	}
	if (move == 3) {
		if (matrix[2][2] == 0) {
			return 1;
		}
	}
	if (move == 4) {
		if (matrix[1][0] == 0) {
			return 1;
		}
	}
	if (move == 5) {
		if (matrix[1][1] == 0) {
			return 1;
		}
	}
	if (move == 6) {
		if (matrix[1][2] == 0) {
			return 1;
		}
	}

	if (move == 7) {
		if (matrix[0][0] == 0) {
			return 1;
		}
	}
	if (move == 8) {
		if (matrix[0][1] == 0) {
			return 1;
		}
	}
	if (move == 9) {
		if (matrix[0][2] == 0) {
			return 1;
		}
	}
	return 0;
}

void setMove(int matrix[3][3], int move, int value) {
	if (move == 1) {
		matrix[2][0] = value; 
	}
	if (move == 2) {
		matrix[2][1] = value; 
	}
	if (move == 3) {
		matrix[2][2] = value; 
	}
	if (move == 4) {
		matrix[1][0] = value; 
	}
	if (move == 5) {
		matrix[1][1] = value; 
	}
	if (move == 6) {
		matrix[1][2] = value; 
	}

	if (move == 7) {
		matrix[0][0] = value; 
	}
	if (move == 8) {
		matrix[0][1] = value; 
	}
	if (move == 9) {
		matrix[0][2] = value; 
	}
}

void drawGame(int matrix[3][3]) {
	system("clear");
	drawMatrix(matrix);
	drawRules();
	int primul = -1;
	int queuePlayer = 0;
	printf("Alege litera, 1 pentru X si 2 pentru 0\n");
	//Zona de cod unde primul jucator isi alege litera
	while (primul == -1) {
		scanf("%d", &primul);
		if (primul != 1 && primul != 2) {
			primul = -1;
			printf("Ai introdus o valoare gresita, mai scrie o data\n");
		}
	}
	while (checkGame(matrix) == 0) {
		if (queuePlayer == 0) {
			printf("E randul jucatorului unu\n");
		} else {
			printf("E randul jucatorului doi\n");
		}
		int move = -1;
		while (move == -1) {
			scanf("%d", &move);
			if (move >= 1 && move <= 9) {
				if (isEmpty(matrix, move) == 1) {
					if (queuePlayer == 0 && primul == 1) {
						setMove(matrix, move, 1);
					} else if (queuePlayer == 0 && primul == 2) {
						setMove(matrix, move, 2);
					} else if (queuePlayer == 1 && primul == 1) {
						setMove(matrix, move, 2);
					} else if (queuePlayer == 1 && primul == 2) {
						setMove(matrix, move, 1);
					}
				} else {
					printf("Casuta ocupata, alege alta casuta\n");
					move = -1;
				}
			} else {
				printf("Introdu miscarea din nou\n");
				move = -1;
			}
		}
		if (queuePlayer == 0) {
			queuePlayer = 1;
		} else {
			queuePlayer = 0;
		}
		system("clear");
		drawMatrix(matrix);
	}
	if (checkGame(matrix) == 10) {
		printf("A castigat jucatorul cu X\n");
	} else if (checkGame(matrix) == 20) {
		printf("A castigat jucatorul cu O\n");
	} else {
		printf("Nu a castigat nimeni\n");
	}
}

int main() {
	//0 va fi liber
	//1 va fi X
	//2 va fi 0
	int matrix[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	drawGame(matrix);
	return 0;
}