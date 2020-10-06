#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include "lib.h"
#include "record.h"

void zad1() {
	int N2 = 10;
	int m2[11][11];
	List relist[11];
	car temp;

	srand(time(NULL)); // заполнение
	for (int i = 0; i < N2; i++) {
		for (int j = (1 + i); j < N2; j++) {
			m2[i][j] = rand() % 2;
			m2[j][i] = m2[i][j];
		}
	}
	for (int i = 0; i < N2; i++) { // обнуление главной диагонали
		m2[i][i] = 0;
	}

	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	//////////****************////////////////
	printf("\n");

	for (int i = 0; i < N2; i++) {
		printf("V%d:", i + 1);
		for (int j = 0; j < N2; j++) {
			if (m2[i][j]) {
				temp.nomer = j;
				if (relist[i].GetSize() == 0) {
					relist[i].push_front(temp);
					printf(" v%d", j+1);
				}
				else {
					relist[i].push_back(temp);
					printf(" v%d", j+1);
				}
			}
		}
		printf("\n");
	}
	///////////////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	printf("\n");

	int kol1, kol2;
	printf("Vvedite nomera vershin dla otojdectvlenia: ");
	scanf("%d%d", &kol1, &kol2);
	kol1--;
	kol2--;

	for (int i = 0; i < N2; i++) { // отождествление
		if (m2[kol2][i]) {
			m2[kol1][i] = 1;
			m2[i][kol1] = 1;
		}
	}
	//// изменение размера массива
	for (int i = 0; i < kol2; i++) {
		for (int j = kol2; j < (N2 - 1); j++) {
			m2[i][j] = m2[i][j + 1];
			m2[j][i] = m2[j + 1][i];
		}
	}
	for (int i = kol2; i < (N2 - 1); i++) {
		for (int j = kol2; j < (N2 - 1); j++) {
			m2[i][j] = m2[i + 1][j + 1];
		}
	}
	m2[kol1][kol1] = 1;
	N2--;
	////
	for (int i = 0; i < N2; i++) { // вывод массива
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}
	N2++;
	///////////////*********************//////////////
	bool flag(!true);
	for (int i = 0; i < relist[kol2].GetSize(); i++) {
		flag = false;
		for (int j = 0; j < relist[kol1].GetSize(); j++) {
			if (relist[kol2][i].nomer == relist[kol1][j].nomer) {
				flag = true;
			}
		}
		if (!flag) {
			relist[kol1].push_back(relist[kol2][i]);
		}
	}

	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < relist[i].GetSize(); j++) {
			if (relist[i][j].nomer == kol2) {
				relist[i].removeAt(j);
			}
			if (relist[i][j].nomer > kol2) {
				relist[i][j].nomer--;
			}
		}
	}

	for (int i = kol2; i < N2; i++) {
		relist[i].clear();
		for (int j = 0; j < relist[i + 1].GetSize(); j++) {
			relist[i].push_back(relist[i + 1][j]);
		}
	}
	temp.nomer = kol1;
	relist[kol1].push_back(temp);

	printf("\n");
	printf("\n");
	N2--;

	for (int i = 0; i < N2; i++) {
		printf("V%d:", i + 1);
		for (int j = 0; j < relist[i].GetSize(); j++) {
			printf(" v%d", relist[i][j].nomer + 1);
		}
		printf("\n");
	}
	////////////////////////////////////////////////////////////////
	printf("\n");
	printf("\n");

	printf("Vvedite nomera vershin dla stagivania rebra: ");
	scanf("%d%d", &kol1, &kol2);
	kol1--;
	kol2--;

	if (m2[kol1][kol2]) {
		for (int i = 0; i < N2; i++) { // отождествление
			if (m2[kol2][i]) {
				m2[kol1][i] = 1;
				m2[i][kol1] = 1;
			}
		}
		//// изменение размера массива
		for (int i = 0; i < kol2; i++) {
			for (int j = kol2; j < (N2 - 1); j++) {
				m2[i][j] = m2[i][j + 1];
				m2[j][i] = m2[j + 1][i];
			}
		}
		for (int i = kol2; i < (N2 - 1); i++) {
			for (int j = kol2; j < (N2 - 1); j++) {
				m2[i][j] = m2[i + 1][j + 1];
			}
		}
		m2[kol1][kol1] = 1;
		
		//// ************//////////

		bool flag(!true);
		for (int i = 0; i < relist[kol2].GetSize(); i++) {
			flag = false;
			for (int j = 0; j < relist[kol1].GetSize(); j++) {
				if (relist[kol2][i].nomer == relist[kol1][j].nomer) {
					flag = true;
				}
			}
			if (!flag) {
				relist[kol1].push_back(relist[kol2][i]);
			}
		}

		for (int i = 0; i < N2; i++) {
			for (int j = 0; j < relist[i].GetSize(); j++) {
				if (relist[i][j].nomer == kol2) {
					relist[i].removeAt(j);
				}
				else {
					if (relist[i][j].nomer > kol2) {
						relist[i][j].nomer--;
					}
				}
			}
		}

		for (int i = kol2; i < N2; i++) {
			relist[i].clear();
			for (int j = 0; j < relist[i + 1].GetSize(); j++) {
				relist[i].push_back(relist[i + 1][j]);
			}
		}
	}
	else {
		printf("Vershini ne smejnie\n");
	}

	N2--;

	for (int i = 0; i < N2; i++) { // вывод массива
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");

	for (int i = 0; i < N2; i++) {
		printf("V%d:", i + 1);
		for (int j = 0; j < relist[i].GetSize(); j++) {
			printf(" v%d", relist[i][j].nomer + 1);
		}
		printf("\n");
	}
	///////////////////////////////////////////////////////////////
	printf("\n");
	printf("\n");

	printf("Vvedite nomer vershini dla rassheplenia: ");
	scanf("%d", &kol1);

	kol1--;
	int sum = 0;

	for (int i = 0; i < N2; i++) { // счётчик смежных вершин
		if (m2[kol1][i]) {
			sum++;
			kol2 = i;		// просто узнать 1 смежную вершину
		}
	}

	for (int i = 0; i < 11; i++) {
		m2[N2][i] = 0;
		m2[i][N2] = 0;
	}

	if (!sum) {
		m2[kol1][N2] = 1;
		m2[N2][kol1] = 1;
		m2[N2][N2] = 0;
	}
	else {
		if (sum == 1) {
			for (int i = 0; i < N2; i++) { // копирование значений 1 вершины в другую
				m2[N2][i] = m2[kol1][i];
				m2[i][N2] = m2[i][kol1];
			}
			m2[N2][kol1] = 1;		// коррекция
			m2[kol1][N2] = 1;
			m2[N2][N2] = 0;
		}
		else {                 // создание новой вершины
			m2[N2][kol2] = 1;  // в 10 строчку под номером kol2
			m2[N2][kol1] = 1;  // создание связи с расщепляемой вершиной
			m2[kol2][N2] = 1;  // в строчку kol2 под номером 10	
			m2[kol1][N2] = 1;  // создание связи с расщепляемой вершиной
			m2[kol1][kol2] = 0;// вычёркивание связи с одной из вершин 
			m2[kol2][kol1] = 0;
			m2[N2][N2] = 0;
		}
	}

	////////////////***************/////////////
	if (!relist[kol1].GetSize()) {
		temp.nomer = kol1;
		relist[N2].push_back(temp);
		temp.nomer = N2;
		relist[kol1].push_back(temp);
	}
	else {
			temp.nomer = kol1;
			relist[N2].push_back(temp);
			temp.nomer = N2;
			relist[kol1].push_back(temp);
			relist[N2].push_back(relist[kol1][relist[kol1].GetSize()-1]);
			if (relist[kol1].GetSize() > 1) {
				relist[kol1].removeAt(relist[kol1].GetSize()-1);
			}
	}

	N2++;
	///////////////////////////////////////////////////////////////

	for (int i = 0; i < N2; i++) { // вывод массива
		for (int j = 0; j < N2; j++) {
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");

	for (int i = 0; i < N2; i++) {
		printf("V%d:", i + 1);
		for (int j = 0; j < relist[i].GetSize(); j++) {
			printf(" v%d", relist[i][j].nomer + 1);
		}
		printf("\n");
	}

	_getch();
}
