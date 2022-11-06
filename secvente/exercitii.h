#include "func.h"
#pragma once

//142. cea mai lunga secventa de elemente prime consecutive, ale caror oglindire sunt tot nr prime

void sol142() {
	int v[100], n, st, dr;
	citireVect(v, n);
	maxSecvPrim(v, n, st, dr);
	for (int i = st; i <= dr; i++) {
		cout << v[i] << ' ';
	}
}

//143. sa se afiseze secventa palindromica de lungime maxima

void sol143() {
	int v[100], n, st, dr;
	citireVect2(v, n);
	//cout << palindrom(v, n, 0, 5);
	secvMaxPalindrom(v, n, st, dr);
	for (int i = st; i <= dr; i++) {
		cout << v[i] << ' ';
	}
}