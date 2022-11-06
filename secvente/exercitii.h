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

//144. sa se afiseze secventa de lungime maxima
//care incepe si se sfarseste cu acelasi numar

void sol144() {
	int v[100], n, st, dr;
	citireVect3(v, n);
	secvMaxAcelasiNumar(v, n, st, dr);
	for (int i = st; i <= dr; i++) {
		cout << v[i] << ' ';
	}
}

//145. sa se decida daca y este subsir al lui x
//(daca exista un nr k ai xk=y0, xk+1=y1 ...)

void sol145() {
	int x[100], n, y[100], m;
	citireVect4(x, n, y, m);
	cout << esteSubsir(x, n, y, m);
}

//146. sa se determine panta de lungime maxima

void sol146() {
	int v[100], n, st, dr;
	citireVect5(v, n);
	pantaMax(v, n, st, dr);
	for (int i = st; i <= dr; i++) {
		cout << v[i] << ' ';
	}
}

//148. secventa maxima in care fiecare componenta are acelasi numar de cifre distincte

void sol148() {
	int v[100], n, st, dr;
	citireVect6(v, n);
	secvMaxCifreDistincte(v, n, st, dr);
	for (int i = st; i <= dr; i++) {
		cout << v[i] << ' ';
	}
}

//149. secventa max pt care suma elementelor se divide cu n

void sol149() {
	int v[100], d, n=2, st, dr;
	citireVect6(v, d);
	secvMaxSumaDivizibila(v, d, st, dr, n);
	for (int i = st; i <= dr; i++) {
		cout << v[i] << ' ';
	}
}