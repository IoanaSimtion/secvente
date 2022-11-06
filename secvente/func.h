#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//todo funtie ce citeste un vector

void citire(int v[], int& d) {
	ifstream f("citire.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

//todo functie ce afiseaza un vector

void afisare(int v[], int d) {
	for (int i = 0; i < d; i++) {
		cout << v[i] << ' ';
	}
}

//todo functie ce determina secventa maxima de elemente nule

void secvElementeNule(int v[], int d, int& st, int& dr) {
	st = 1;
	dr = 0;
	for (int i = 0; i < d; i++) {
		if (v[i] == 0) {
			int j = i;
			while (j + 1 < d && v[j + 1] == 0) {
				j++;
			}
			if (j - i + 1 > dr - st + 1) {
				st = i;
				dr = j;
			}
			i = j;
		}
	}
}

//todo functie ce determina ultima secventa max de elemente egale

void secvElementeEgale(int v[], int d, int& st, int& dr) {
	st = 1, dr = 0;
	for (int i = 0; i < d - 1; i++) {
		if (v[i] == v[i + 1]) {
			int j = i;
			while (j + 1 < d && v[j] == v[j + 1]) {
				j++;
			}
			if (j - i + 1 >= dr - st + 1) {
				st = i;
				dr = j;
			}
			i = j;
		}
	}
}

//todo functie ce citeste 2 vectori

void citire2(int a[], int& n, int b[], int& m) {
	ifstream f("citire2.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	f >> m;
	for (int i = 0; i < m; i++) {
		f >> b[i];
	}
}

//todo functie ce returneaza nr de aparitii a secventei y in x

int nrApSecv(int a[], int b[], int d, int d2) {
	int ct = 0;
	for (int i = 0; i < d; i++) {
		int indice = 0;
		if (a[i] == b[indice]) {
			int j = i;
			while (j + 1 < d && a[j] == b[indice]) {
				j++;
				indice++;
			}
			if (indice == d2) {
				ct++;
			}
		}
	}
	return ct;
}

void citireSolutia4(int v[], int& n, int& t, int& k) {
	ifstream f("citire3.txt");
	f >> n >> t >> k;
	for (int i = 0; i < n; i++) {
		f >> v[i];
	}
}

//todo functie ce determia câte secvențe din șir au lungimea k și sunt formate din valori mai mici sau egale cu t

int contorSecvente(int v[], int n, int t, int k) {
	int ct = 0, lungime;
	for (int i = 0; i < n; i++) {
		lungime = 0;
		if (v[i] <= t) {
			int j = i;
			while (j + 1 < n && v[j] <= t) {
				j++;
				lungime++;
			}
			if (lungime == k) {
				ct++;
			}
		}
	}
	return ct;
}

//todo functie ce determina cea mai lungă secvență de elemente din vector care începe și se termină cu aceeași valoare

void secventaMaxima(int v[], int n, int& st, int& dr) {
	st = 1, dr = 0;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j + 1 < n && v[j + 1] != v[i]) {
			j++;
		}
		if (j - i + 1 > dr - st + 1) {
			st = i, dr = j;
		}
		i = j;
	}
}

//todo functie ce determina câte secvențe ale vectorului au toate elementele egale

int secventeEgale(int v[100], int d) {
	int ct = 0;
	for (int i = 0; i < d; i++) {
		int j = i + 1;
		ct++;
		while (v[j] == v[i] && j + 1 < d) {
			j++;
			ct++;
		}

	}
	return ct;
}

//todo functie ce verifica daca un numar este prim

bool prim(int numar) {
	for (int i = 2; i < numar / 2; i++) {
		if (numar % i == 0) {
			return false;
		}
	}
	return true;
}

//todo functie ce determina suma elementelor din secvenţa determinată de primul şi ultimul element prim

int sumaElementeSecventa(int v[], int d) {
	int suma = 0, st = 0, dr = 0;
	bool gasit = 0;
	for (int i = 0; i < d && !st; i++) {
		if (prim(v[i])) {
			st = i;
			for (int j = d - 1; j > i && !dr; j--) {
				if (prim(v[j])) {
					dr = j;
				}
			}
		}
	}
	for (int i = st; i <= dr; i++) {
		suma += v[i];
	}
	return suma;
}

//todo functie ce determina o secventa de elemente din şir cu suma elementelor egală cu S

void secventaS(int v[], int d, int& st, int& dr, int S) {
	st = 1, dr = 0;
	bool gasit = 0;
	for (int i = 0; i < d && !gasit; i++) {
		int suma = 0;
		if (v[i] <= S) {
			suma = suma + v[i];
			int j = i;
			while (j + 1 < d && v[j + 1] + suma <= S) {
				j++;
				suma = suma + v[j];
			}
			if (suma == S) {
				st = i, dr = j;
				gasit = 1;
			}
			i = j;
		}
	}
}

void citire4(int v[], int& d) {
	ifstream f("citire4.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

//toto funtie ce numărul secvenţelor din şir care au produsul elementelor egal cu 2^k

int numarSecvente(int v[], int d, int nr) {
	int ct = 0;
	for (int i = 0; i < d; i++) {
		int produs = 1;
		if (v[i] <= nr) {
			produs = produs * v[i];
			int j = i;
			while (j + 1 < d && produs * v[j + 1] <= nr) {
				j++;
				produs = produs * v[j];
			}
			if (produs == nr) {
				ct++;
			}
		}
	}
	return ct;
}

void citire5(int v[], int& d) {
	ifstream f("citire5.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

//todo fucntie ce determina cea mai lungă secvenţă de elemente din şir 
//cu proprietatea că oricare două valori consecutive în secvenţă au parităţi diferite

void secventaParitatiDiferite(int v[], int d, int& st, int& dr) {
	st = 1, dr = 0;
	int sumaMax = 0;
	for (int i = 0; i < d - 1; i++) {
		int suma = 0;
		if (v[i] % 2 != v[i + 1] % 2) {
			suma = suma + v[i];
			int j = i;
			while (j + 1 < d && v[j] % 2 != v[j + 1] % 2) {
				j++;
				suma = suma + v[j];
			}
			if (j - i + 1 >= dr - st + 1 && suma >= sumaMax) {
				sumaMax = suma;
				st = i, dr = j;
			}
			i = j;
		}
	}
}

//todo functie ce determina câte secvenţe maximale cu elementele ordonate crescător conţine şirul

int ctScventeCresc(int v[], int d) {
	int ct = 0, dr;
	for (int i = 0; i < d; i++) {
		if (v[i] < v[i + 1]) {
			int j = i;
			while (j + 1 < d && v[j] < v[j + 1]) {
				j++;
			}
			ct++;
			i = j;
		}
	}
	return ct;
}

//todo functie ce determina suma elementelor din secvenţa determinată de i şi j

int sumaElemente(int v[], int d, int i, int j) {
	int suma = 0;
	for (int k = i; k <= j; k++) {
		suma = suma + v[k];
	}
	return suma;
}

//todo functie ce determina, pentru fiecare pereche (i,j), suma elementelor din secvenţa determinată de i şi j.

void sumaPerechi(int v[], int& d, int& m) {
	int x, y;
	ifstream f("citire6.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
	f >> m;
	for (int i = 0; i < m; i++) {
		f >> x >> y;
		cout << sumaElemente(v, d, x, y) << ' ';
	}
}

//todo functie ce determina suma elementelor din secvența determinată de primul și ultimul element impar

int sumaSecvImp(int v[], int d) {
	int suma = 0, st = 0, dr = 0;
	for (int i = 0; i < d && !st; i++) {
		if (v[i] % 2 == 1) {
			st = i;
			for (int j = d - 1; j > st && !dr; j--) {
				if (v[j] % 2 == 1) {
					dr = j;
				}
			}
		}
	}
	for (int i = st; i <= dr; i++) {
		suma = suma + v[i];
	}
	return suma;
}

void citire7(int a[], int& n, int b[], int& m) {
	ifstream f("citire2.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	f >> m;
	for (int i = 0; i < m; i++) {
		f >> b[i];
	}
}

//todo functie ce returneaza poziția din vectorul x de unde începe secvența y

int pozInceput(int x[], int n, int y[], int m) {
	int poz = -1;
	for (int i = 0; i < n; i++) {
		int j = 0;
		if (x[i] == y[j]) {
			poz = i;
			while (x[i] == y[j]) {
				j++;
				i++;
			}
			if (j == m) {
				return poz;
			}
		}
	}
}

//todo functie ce determina cea mai lungă secvență de elemente pare din vector

void secventaNrPare(int v[100], int d, int& st, int& dr) {
	st = 1, dr = 0;
	int sumaMax = 0;
	for (int i = 0; i < d; i++) {
		int suma = 0;
		if (v[i] % 2 == 0) {
			suma = suma + v[i];
			int j = i;
			while (j + 1 < d && v[j + 1] % 2 == 0) {
				j++;
				suma = suma + v[j];
			}
			if (j - i + 1 >= dr - st + 1 && suma >= sumaMax) {
				sumaMax = suma;
				st = i, dr = j;
			}
			i = j;
		}
	}
}


//todo functie ce determina lungimea maximă a unei secvențe de elemente divizibile cu 10
//și numărul de secvențe de lungime maximă cu elemente divizibile cu 10.

int secvente10(int v[], int d, int& ct) {
	int lungimeMax = 0;
	for (int i = 0; i < d; i++) {
		if (v[i] % 10 == 0) {
			int j = i;
			while (j + 1 < d && v[j + 1] % 10 == 0) {
				j++;
			}
			if (j - i + 1 > lungimeMax) {
				lungimeMax = j - i + 1;
				ct = 0;
			}
			if (lungimeMax == j - i + 1) {
				ct++;
			}
		}
	}
	return lungimeMax;
}

void citire7(int v[], int& d) {
	ifstream f("citire7.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

//todo functie ce determina poz minimului

int pozMinim(int v[], int d) {
	int poz = 0, min = INT_MAX;
	for (int i = 0; i < d; i++) {
		if (v[i] < min) {
			min = v[i];
			poz = i;
		}
	}
	return poz;
}

//todo functie ce determina poz maximului

int pozMaxim(int v[], int d) {
	int poz, max = INT_MIN;
	for (int i = 0; i < d; i++) {
		if (v[i] > max) {
			max = v[i];
			poz = i;
		}
	}
	return poz;
}

//todo functie ce deterina suma elementelor din secvenţa ce uneşte cel mai mic şi cel mai mare element din şir

int suma(int v[], int st, int dr) {
	int suma = 0;
	for (int i = st; i <= dr; i++) {
		suma = suma + v[i];
	}
	return suma;
}

//todo functie ce oglindeste o secventa

void oglinire(int v[], int st, int dr) {
	int i = st, j = dr;
	while (i < j) {
		swap(v[i], v[j]);
		i++;
		j--;
	}
}

//todo fucntie ce oglindeste fiecare secvență de elemente determinată de o pereche (i,j)

void oglindireSecvente(int v[], int& d, int& m) {
	int x, y;
	ifstream f("citire8.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
	f >> m;
	for (int i = 0; i < m; i++) {
		f >> x >> y;
		oglinire(v, x, y);
	}
}

void citire9(int v[], int& d) {
	ifstream f("citire9.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

//todo functie ce determina secvența de elemente cu suma maximă

void secvSumaMax(int v[], int d, int& st, int& dr) {
	int sumaMax = 0;
	for (int i = 0; i < d; i++) {
		int suma = 0;
		if (v[i] + v[i + 1] >= suma) {
			int j = i;
			suma = suma + v[i];
			while (j + 1 < d) {
				j++;
				suma = suma + v[j];
			}
			if (suma > sumaMax && j - i + 1 > dr - st + 1) {
				st = i, dr = j;
				sumaMax = suma;
			}
		}
	}

}

void citire10(int v[], int& d) {
	ifstream f("citire10.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

int sumaSubsecvente(int v[], int d) {
	int suma = 0;
	for (int i = 0; i < d; i++) {
		int j = i;
		suma = suma + v[i];
		while (j + 1 <= d) {
			suma = suma + v[j];
			j++;
		}
	}
	return suma;
}


//todo citire

void citireVector(int v[], int& d) {
	ifstream f("numere.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

//algoritm secvente:

void secvente(int v[], int d, int& st, int& dr) {
	

	int sMax = -1;

	int s = -1;
	int start;

	for (int i = 0; i < d; i++) {

		if (s < 0) {
			s = 0;
			start = i;
		}
		s += v[i];
		if (s > sMax) {
			sMax = s;
			st = start;
			dr = i;
		}
	}
	cout << sMax << endl;

}

void citireVect(int v[], int& d) {
	ifstream f("citire.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

//todo functie ce returneaza oglinditul unui numar

int oglindit(int numar) {
	int ogl = 0;
	while (numar) {
		ogl = ogl * 10 + numar % 10;
		numar/= 10;
	}
	return ogl;
}

//todo functie ce determina cea mai lunga secventa de elemente prime consecutive, ale caror oglindire sunt tot nr prime

void maxSecvPrim(int v[], int n, int& st, int& dr) {
	st = 1, dr = 0;
	for (int i = 0; i < n; i++) {
		if (prim(v[i]) && prim(oglindit(v[i]))) {
			int j = i;
			while (j + 1 < n && (prim(v[j + 1]) && prim(oglindit(v[j + 1])))) {
				j++;
			}
			if (j - i + 1 > dr - st + 1) {
				st = i, dr = j;
			}
			i = j;
		}
	}
}

void citireVect2(int v[], int& d) {
	ifstream f("citire2.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

//todo functie ce verifica daca o secventa este palindromica

bool palindrom(int v[], int d, int poz, int poz2) {
	int i = poz, j = poz2;
	while (i < j) {
		if (v[i] != v[j]) {
			return false;
		}
		i++, j--;
	}
	return true;
}

//todo functie ce determina secventa palindromica de lungime maxima

void secvMaxPalindrom(int v[], int n, int& st, int& dr) {
	st = 1, dr = 0;
	for (int i = 0; i < n; i++) {
		int j = n;
		while (i < j && !palindrom(v, n, i, j)) {
			j--;
		}
		if (j - i + 1 > dr - st + 1) {
			st = i, dr = j;
		}
	}
}

//todo functie ce determina secventa de lungime maxima care incepe si se sfarseste cu acelasi numar

void secvMaxAcelasiNumar(int v[], int d, int& st, int& dr) {
	st = 1, dr = 0;
	for (int i = 0; i < d; i++) {
		int j = d;
		while (i < j && v[i] != v[j]) {
			j--;
		}
		if (j - i + 1 > dr - st + 1) {
			st = i, dr = j;
		}
	}
}

void citireVect3(int v[], int& d) {
	ifstream f("citire3.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		f >> v[i];
	}
}

void citireVect4(int a[], int& n, int b[], int& m) {
	ifstream f("citire4.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	f >> m;
	for (int i = 0; i < m; i++) {
		f >> b[i];
	}
}

//todo functie ce verifica daca y este subsir al lui x

bool esteSubsir(int x[], int n, int y[], int m) {
	for (int i = 0; i < n; i++) {
		int j = 0;
		if (x[i] == y[j]) {
			while (x[i + 1] == y[j + 1]) {
				i++;
				j++;
			}
			if (j == m - 1 ) {
				return true;
			}
		}
	}
	return false;
}