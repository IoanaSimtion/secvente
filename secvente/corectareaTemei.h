#pragma once
#include "func.h"

//cerinta: Se dă un șir cu n elemente, numere întregi. Determinați secvența de elemente cu suma maximă.

void rezolvareProblema() {
	int v[100], n, st=0, dr=0;
	citireVector(v, n);
	//afisare(v, n);
	secvente(v, n, st, dr);
	cout << st << ' ' << dr;
}