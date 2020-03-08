#include<iostream>
#include<fstream>
#include<vector>
#include <sstream>

using namespace std;

struct Klient{
	int numerKlienta;
	int zadluzenie;
};

vector<Klient> klienci;

int iloscKlientowZ();
int kwotaZadluzenia();
void pobierzDane(char[]); 
void zapiszPlik();

int main(){
	pobierzDane("klienci.txt");
    return 0;
}

void pobierzDane(char plik[]){
	ifstream klientFileHandler(plik);
   	string linia;
	if (klientFileHandler.is_open()){
		
		while(getline(klientFileHandler, linia, ',')){
			stringstream ss(linia);
			string tmp[2];
			string tStr;
			for (int i = 0; ss >> tStr; i++) {
				tmp[i] = tStr;  
				if (ss.peek() == ',')
					ss.ignore();
			}
			klienci.push_back(
				Klient {.numerKlienta=tmp[0], .zadluzenie=tmp[1]}
			);
			cout<<linia<<"\n";
		}
	}
	else
	{
		cout<<"Brak pliku";
	}
	klientFileHandler.close();
}

