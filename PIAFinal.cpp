#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

void Agendar();
void Listas();
void Modificar();
void Eliminar();
void Salida();

int* price;
int* unitprice;
int* unitcant;
int* subtotal;
int* total;
int* id = 0;
string* hora;
string* name;
string* trat;
float iva = 0.16;
int numreg;

int main()
{
	int opcion;
	printf("Bienvenido a la Clinica *Nombre de Clinica*\n");
	printf("\n");
	printf("Favor de selecionar una opcion:\n");
	printf("1.- Agendar una cita\n");
	printf("2.- Modificar una cita\n");
	printf("3.- Eliminar una cita\n");
	printf("4.- Lista de citas vigentes\n");
	printf("5.- Salir\n");
	scanf_s("%d", &opcion);
	system("cls");

	switch (opcion)
	{
	case 1:
	{
		Agendar();
		return main();
		break;
	}

	case 2:
	{
		Modificar();
		return main();
		break;
	}

	case 3:
	{
		Eliminar();
		return main();
		break;
	}

	case 4:
	{
		Listas();
		return main();
		break;
	}

	case 5:
	{
		Salida();
		break;
	}

	}
}

void Agendar()
{
	printf("Ingrese la cantidad de citas que desea dar de alta: ");
	scanf_s("%d", &numreg);

	system("cls");

	price = new int[numreg];
	unitprice = new int[numreg];
	unitcant = new int[numreg];
	unitcant = new int[numreg];
	subtotal = new int[numreg];
	total = new int[numreg];
	hora = new string[numreg];
	name = new string[numreg];
	trat = new string[numreg];

	for (int i = 0; i < numreg; i++)
	{
		printf("Si desea agendar una cita por favor introduzca los siguientes datos:\n");
		cin.ignore();
		printf("\n");

		printf("Ingrese el nombre del paciente:\n");
		getline(cin, name[i]);
		printf("\n");

		printf("Agendar hora de la cita en formato de 24 hrs:\n");
		scanf_s("%d", &hora[i]);
		cin.ignore();
		printf("\n");

		printf("Motivo de la cita:\n");
		getline(cin, trat[i]);
		printf("\n");

		printf("Precio del tratamiento:\n");
		scanf_s("%d", &unitprice[i]);
		printf("\n");

		printf("Cantidad del tratamiento:\n");
		scanf_s("%d", &unitcant[i]);
		printf("\n");

		subtotal[i] = unitcant[i] * unitprice[i];
		total[i] = subtotal[i] + (subtotal[i] * 0.16);
		printf("\n");
		printf("Precio total: %d\n", total[i]);

		system("pause");
		system("cls");
	}
}

void Modificar()
{
	int j;
	int opcion;
	printf("Ingrese el numero de cita que desea modificar: ");
	scanf_s("%d", &j);
	j = j - 1;

	system("cls");

	printf("Ingrese que desea modificar:\n");
	printf("1] Nombre\n");
	printf("2] Motivo de la cita\n");
	printf("3] Costo del tratamiento\n");
	printf("4] Cantidad de citas\n");
	printf("5] Hora de la cita\n");
	scanf_s("%d", &opcion);
	system("cls");

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			cin.ignore();
			printf("Ingrese el nombre:\n");
			getline(cin, name[i]);
			system("cls");
		}
		break;

	case 2:
		for (int i = j; i == j; i++)
		{
			cin.ignore();
			printf("Ingrese el motivo de la cita:\n");
			getline(cin, trat[i]);
			system("cls");
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el precio de la cita:\n");
			cin >> unitprice[i];
			system("cls");
		}
		break;

	case 4:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese la cantidad de citas:\n");
			cin >> unitcant[i];
			system("cls");
		}
		break;

	case 5:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese la nueva hora de la cita:\n");
			cin >> hora[i];
			system("cls");
		}
		break;
	}
}

void Listas()
{
	for (int i = 0; i < numreg; i++)
	{

		cout << " Cita " << i + 1 << endl;
		cout << " El nombre del paciente es: " << name[i] << endl;
		cout << " La hora dela cita es: " << hora[i];
		cout << " EL motivo es: " << trat[i] << endl;
		cout << " El precio es de: " << unitprice[i] << endl;
		cout << " La cantidad de citas es de: " << unitcant[i] << endl;
		cout << " El precio total es de: " << total[i] << endl;
	}
	system("pause");
	system("cls");
}

void Eliminar()
{
	int x;
	printf("Ingrese el numero de cita que desea eliminar:\n");
	scanf_s("%d", &x);
	x = x - 1;

	system("cls");

	for (int i = x; i == x; i++)
	{
		name[i] = " ";
		trat[i] = " ";
		hora[i] = " ";
		unitcant[i] = 0;
		unitprice[i] = 0;
		total[i] = 0;
		printf("La cita fue eliminada con exito.\n");
		system("pause");
		system("cls");
	}
}

void Salida()
{
	ofstream archivo;
	string narch;
	string texto;
	int texto2{};

	narch = "Citas dentales";
	archivo.open(narch.c_str(), ios::app);

	if (archivo.fail())
	{
		printf("No se pudo guardar el archivo.\n");
		exit(1);
	}

	for (int i = 0; i < numreg; i++)
	{
		texto = name[i];
		archivo << texto << "\t" << "\t";
		texto = trat[i];
		archivo << texto2 << "\t " << "\t";
		texto = hora[i];
		archivo << texto << "\t " << "\t";
		texto2 = unitcant[i];
		archivo << texto2 << "\t " << "\t";
		texto2 = total[i];
		archivo << texto2 << "\t" << "\t";

	}
	archivo.close();
}