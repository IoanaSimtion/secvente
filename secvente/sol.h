
#include "func.h"
#pragma once


/*518: Se dă un vector cu n elemente numere naturale.
Determinați cea mai lungă secvență de elemente nule din vector.
Dacă în vector există mai multe secvențe de elemente nule de lungime maximă se va determina cea mai din stânga.*/

void sol1() {
	int d, v[100], st, dr;
	citire(v, d);
	//afisare(v, d);
	secvElementeNule(v, d, st, dr);
	cout << st << ' ' << dr;
}


/*523: Se dă un vector cu n elemente, numere naturale.
Determinați cea mai lungă secvență de elemente egale din vector.
Dacă în vector există mai multe secvențe de elemente egale de lungime maximă se va determina cea mai din dreapta.*/

void sol2() {
	int d, v[100], st, dr;
	citire(v, d);
	secvElementeEgale(v, d, st, dr);
	cout << st << ' ' << dr;
}


/*520: Se dă un vector x cu n elemente, numere naturale și un vector y cu m elemente, numere naturale.
Să se determine de câte ori este vectorul y secvență în vectorul x.*/

void sol3() {
	int x[100], n, y[100], m;
	citire2(x, n, y, m);
	//afisare(x, n);
	//afisare(y, m);
	cout << nrApSecv(x, y, n, m);
}


/*862: Se dă un vector cu n elemente, numere naturale și două numere t și k.
Să se determine câte secvențe din șir au lungimea k și sunt formate din valori mai mici sau egale cu t.*/

void sol4() {
	int v[100], n, t, k;
	citireSolutia4(v, n, t, k);
	cout << contorSecvente(v, n, t, k);
}


/*524: Se dă un vector cu n elemente, numere naturale.
Determinați cea mai lungă secvență de elemente din vector care începe și se termină cu aceeași valoare.
Dacă în vector există mai multe secvențe corecte de lungime maximă se va determina cea mai din stânga.*/

void sol5() {
	int v[100], n, st, dr;
	citire(v, n);
	//afisare(v, n);
	secventaMaxima(v, n, st, dr);
	cout << st << ' ' << dr;
}


/*578: Se dă un vector cu n elemente, numere naturale.
Determinați câte secvențe ale vectorului au toate elementele egale.*/

void sol6() {
	int v[100], n;
	citire(v, n);
	cout << secventeEgale(v, n);
}

/*298: Se dă un şir format din n elemente, numere naturale.
Calculaţi suma elementelor din secvenţa determinată de primul şi ultimul element prim.*/

void sol7() {
	int v[100], n;
	citire(v, n);
	cout << sumaElementeSecventa(v, n);
}

/*300: Se dă un vector format din n elemente, numere naturale nenule, şi un număr natural S.
Determinaţi, dacă există o secvenţă de elemente din şir cu suma elementelor egală cu S.*/

void sol8() {
	int v[100], n, S = 7, st, dr;
	citire(v, n);
	secventaS(v, n, st, dr, S);
	cout << st << ' ' << dr;
}

/*1839: Se dă un şir format din n numere naturale nenule.
Să se afle numărul secvenţelor din şir care au produsul elementelor egal cu 2^k, unde k este un număr natural dat.*/

void sol9() {
	int v[100], n, k = 3;
	int nr = pow(2, k);
	//cout << nr;
	citire4(v, n);
	cout << numarSecvente(v, n, nr);
}

/*283: Se dă un şir cu n elemente, numere naturale.
Determinaţi cea mai lungă secvenţă de elemente din şir cu proprietatea
că oricare două valori consecutive în secvenţă au parităţi diferite.
Dacă există mai multe secvente de lungime maximă cu această proprietate,
se va determina aceea cu suma elementelor maximă. Dacă există mai multe secvenţe de lungime maximă
cu aceeaşi sumă maximă a elementelor se va determina cea mai din dreapta.*/

void sol10() {
	int v[100], n, st, dr;
	citire5(v, n);
	secventaParitatiDiferite(v, n, st, dr);
	cout << st << ' ' << dr;
}

/*304: Se dă un şir format din n elemente, numere naturale.
Determinaţi câte secvenţe maximale cu elementele ordonate crescător conţine şirul.*/

void sol11() {
	int v[100], n;
	citire5(v, n);
	cout << ctScventeCresc(v, n);
}

/*299: Se dă un vector cu n elemente numere naturale  și m perechi de indici (i,j), cu 1≤i<j≤n.
Să se determine, pentru fiecare pereche (i,j), suma elementelor din secvenţa determinată de i şi j.*/

void sol12() {
	int v[100], n, m;
	sumaPerechi(v, n, m);
}

/*516: Se dă un vector format din n elemente, numere naturale.
Calculați suma elementelor din secvența determinată de primul și ultimul element impar.*/

void sol13() {
	int v[100], n;
	citire5(v, n);
	cout << sumaSecvImp(v, n);
}

/*519: Se dă un vector x cu n elemente, numere naturale și un vector y cu m elemente, numere naturale.
Să se verifice dacă vectorul y este secvență în vectorul x.*/

void sol14() {
	int x[100], n, y[100], m;
	citire7(x, n, y, m);
	cout << pozInceput(x, n, y, m);
}

/*166: Se dau n numere naturale, reprezentând elementele unui vector.
Determinați cea mai lungă secvență de elemente pare din vector.
Dacă există mai multe secvențe cu lungime maximă se va determina cea cu suma elementelor maximă.
Dacă există mai multe astfel de secvențe se va determina cea mai din stânga.*/

void sol15() {
	int v[100], n, st, dr;
	citire5(v, n);
	secventaNrPare(v, n, st, dr);
	cout << st << ' ' << dr;
}

/*4148: Se dau n numere naturale, reprezentând elementele unui vector.
Determinați lungimea maximă a unei secvențe de elemente divizibile cu 10,
precum și numărul de secvențe de lungime maximă cu elemente divizibile cu 10.*/

void sol16() {
	int v[100], n, ct = 0;
	citire7(v, n);
	cout << secvente10(v, n, ct);
	cout << ' ' << ct;
}

/*1446: Se dă un şir format din n numere naturale distincte.
Calculați suma elementelor din secvenţa ce uneşte cel mai mic şi cel mai mare element din şir.*/

void sol17() {
	int v[100], n, poz1, poz2;
	citire7(v, n);
	poz1 = pozMinim(v, n);
	poz2 = pozMaxim(v, n);
	if (poz1 > poz2) {
		swap(poz1, poz2);
	}
	cout << suma(v, poz1, poz2);
}

/*190: Se dă un vector cu n elemente numere naturale și m perechi de indici (i,j), cu 1≤i<j≤n.
Fiecare secvență de elemente determinată de o pereche (i,j) se oglindește –
primul elemente din secvență se interschimbă cu ultimul, al doilea cu penultimul, etc..*/

void sol18() {
	int v[100], n, m;
	/*citire(v, n);
	oglinire(v, 0, 10);
	afisare(v, n);*/
	oglindireSecvente(v, n, m);
	afisare(v, n);
}

//297: Se dă un șir cu n elemente, numere întregi. Determinați secvența de elemente cu suma maximă.

void sol19() {
	int v[100], n, st, dr;
	citire9(v, n);
	secvSumaMax(v, n, st, dr);
	cout << st << ' ' << dr;
}

/*2142: Se consideră un vector cu n elemente numere naturale.
Calculați suma sumelor tuturor subsecvențelor ce se pot forma cu elementele vectorului*/

void sol20() {
	int v[100], n;
	citire10(v, n);
	cout << sumaSubsecvente(v, n);
}