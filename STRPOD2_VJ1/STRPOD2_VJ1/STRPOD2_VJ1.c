/*
Definirati niz sa 10 elemenata tipa struktura osoba (ime, prezime, godina rodjenja).
U glavnom programu napraviti izbornik koji dozvoljava:
- unosenje novog elemenata u niz (na prvo slobodno mjesto),
- brisanje elementa iz niza (brise se zadnji uneseni),
- ispis unesenih elemenata,
- izlaz iz programa.
Unos, brisanje i ispis potrebno rijesiti u funkcijama.
U mainu moze biti izbornik i pozivi funkcija.
Ne smiju se koristiti globalne varijable.
*/
//NAPRAVLJENO

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct osoba
{
	char ime[10];
	char prezime[10];
	int godina_rodjenja;
}osoba;

int unos(int, osoba[]);
int brisi(int, osoba[]);
void ispis(int, osoba[]);

int main()
{
	osoba nizOsoba[MAX];
	int broj_osobe = 0;
	int izbor = 0;
	while (izbor != 4)
	{
		printf("\n\t1. UNOS");
		printf("\n\t2. BRISANJE ZADNJEG CLANA");
		printf("\n\t3. ISPIS");
		printf("\n\t4. KRAJ");
		printf("\nOdaberite radnju koju zelite izvrsiti: ");
		scanf("%d", &izbor);

		switch (izbor)
		{
		case 1:
			broj_osobe = unos(broj_osobe, nizOsoba);
			break;
		case 2:
			broj_osobe = brisi(broj_osobe, nizOsoba);
			break;
		case 3:
			ispis(broj_osobe, nizOsoba);
			break;
		case 4:
			printf("\nKraj programa");
			break;
		default:
			printf("\nUnjeli ste krivi broj");
			break;
		}
	}
	return 0;
}

int unos(int n, osoba x[])
{
	if (MAX == n)
	{
		printf("\nNiz je pun");
	}
	else
	{
		printf("\nUnesite ime osobe: ");
		scanf(" %s", x[n].ime);
		printf("Unesite prezime osobe: ");
		scanf(" %s", x[n].prezime);
		printf("Unesite godinu rodjenja osobe: ");
		scanf("%d", &x[n].godina_rodjenja);
		n++;
	}
	return n;
}

int brisi(int n, osoba x[])
{
	if (0 == n)
	{
		printf("\nNiz je prazan");
	}
	else
	{
		n--;//ode brisemo samo zadnjeg u nizu, odnosno samo smanjujemo niz za jedan, cak niti ne brisemo
	}
	return n;
}

void ispis(int n, osoba x[])
{
	if (0 == n)
	{
		printf("\nNiz je prazan");
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("\nIme: %s", x[i].ime);
			printf("\nPrezme: %s", x[i].prezime);
			printf("\nGodina rodjenja: %d", x[i].godina_rodjenja);
			printf("\n");
		}
	}
}




