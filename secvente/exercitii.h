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