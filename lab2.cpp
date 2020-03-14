#include<iostream>
#include<fstream>
#include<vector>
#include <sstream>

using namespace std;

struct Klient{
	int numerKlienta;
	int zadluzenie;
};

struct Wynik{
  int wynik;
} out;

vector<Klient> klienci;

void menu();
void wyswietlRekord(Klient k);
void wyswietlWszystkichKlientow();
int iloscKlientowZ();
void wyswietlKlientowZ();
int kwotaZadluzenia();
void wyswietlKwoteZadluzenia();
void pobierzDane(string); 
void zapiszDane(string plik, Wynik * out);

int main(){
	pobierzDane("klienci.txt");
  menu();

  return 0;
}



void menu(){
  int wybor = 0;
  do {
    cout << "MENU: " << endl;
    cout << "(1) Wyswietl wszystkich klientow" << endl;
    cout << "(2) Sprawdz ile klientow jest zadluzonych" << endl;
    cout << "(3) Sprawdz jaka jest laczna kwota zadluzenia" << endl;
    cout << "(0) Wyjdz" << endl;
    cin >> wybor;

    switch (wybor)
    {
    case 1:
      wyswietlWszystkichKlientow();
      break;
    case 2:
      wyswietlKlientowZ();
      break;
    case 3:

      break;
    case 4:
      break;
    }
  } while (wybor != 0);
}

void wyswietlRekord(Klient k){
  cout << "Nr klienta: " << k.numerKlienta << ", Kwota zadluzenia: " << k.zadluzenie << endl;
}

void wyswietlWszystkichKlientow(){
  cout  << "==> Lista klientow <==" << endl;
  for(int i = 0; i < klienci.size(); i++){
    wyswietlRekord(klienci[i]);
  }
  cout  << "=======================" << endl;
}

int iloscKlientowZ(){
  int count = 0;
  for(int i = 0; i < klienci.size(); i++){
    if (klienci[i].zadluzenie > 0){
      count++;
    }
  }
  return count;
}

void wyswietlKlientowZ(){
  int ileKlientow = iloscKlientowZ();
  Wynik wynik = {.wynik=ileKlientow};
  zapiszDane("wynik.dat", &wynik);
}



void pobierzDane(string plik){
	ifstream klientFileHandler(plik);
  string linia, l1, tmp;
	int i = 0;
  stringstream ss;
	if (klientFileHandler.is_open()){
		while(getline(klientFileHandler, linia)){
      ss.str(linia);
      while (ss >> tmp){
        if (i % 2 == 0){
          l1 = linia;
        } else {
          klienci.push_back(
            Klient {.numerKlienta=stoi(l1), .zadluzenie=stoi(tmp)}
          );
        }
        i++;
      }
      ss.clear();
      i = 0;
		}
	}
	else
	{
		cout<<"Brak pliku";
	}
	klientFileHandler.close();
}


void zapiszDane(string plik, Wynik * out){
  ofstream z;
  z.open(plik, ios::binary );
  z.write((char*)out, sizeof(*out));
  z.close();
}

