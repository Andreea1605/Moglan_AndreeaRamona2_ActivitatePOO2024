#include<iostream>
using namespace std;
//structura
//pointeri
//vectori
//transmiterea unui vector ca parametru
//citirea unui vector

struct Tara {
	char* denumire;
	int nrLocuitori;
	string capitala;
	bool areIesireLaMare;
};

void afisareTara(Tara tara) {

}

Tara* citirePointerLaTara() {
	Tara* p = new Tara();
	cout << "Capitala:";
	cin >> p->capitala;

	cout << "Denumire:";
	char buffer[100];
	cin >> buffer;
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);

	cout << "Numar locuitori:";
	cin >> p->nrLocuitori;

	cout << "Are iesire la mare?(0-NU;1-DA)";
	cin >> p->areIesireLaMare;

	return p;
}

void afisarePointerLaTara(Tara* pt) {
	cout << "Nume:" << pt->denumire << endl;
	cout << "Numar locuitori:" << pt->nrLocuitori << endl;
	cout << "Capitala:" << pt->capitala << endl;
	cout << "Are iesire la mare:" << (pt->areIesireLaMare ? "DA" : "NU") << endl; //operator ternar
 /*if (pt->areIesireLaMare) {
	cout << "DA" << endl;
	}
	else {
	   cout<< "NU" <<endl;
	   } */
}

int main() {
	Tara tara;
	tara.areIesireLaMare = false;

	Tara* ptara;
	ptara = new Tara();
	ptara->areIesireLaMare = true;
	ptara->capitala = "Bucuresti";
	ptara->denumire = new char[strlen("Romania")+1];
	strcpy_s(ptara->denumire, strlen("Romania") + 1, "Romania");
	ptara->nrLocuitori = 200;

	afisarePointerLaTara(ptara);

	delete[]ptara->denumire;
	delete ptara;
	
	//Tara* p2tara = citirePointerLaTara();
	//afisarePointerLaTara(p2tara);

	Tara* vector;
	vector = new Tara[2];

	int nrPointeri = 2;
	//vector de pointeri
	Tara** pointeri;
	pointeri = new Tara * [nrPointeri];
	for (int i = 0; i < nrPointeri; i++) {
		pointeri[i] = citirePointerLaTara();
	}
	//procesare
	for (int i = 0; i < nrPointeri; i++) {
		afisarePointerLaTara(pointeri[i]);
	}
	//stergere memorie heap
	for (int i = 0; i < nrPointeri; i++) {
		delete[]pointeri[i]->denumire;
		delete pointeri[i];
	}
	delete[]pointeri;
}