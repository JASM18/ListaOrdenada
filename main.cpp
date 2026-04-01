#include <iostream>
#include <cstdlib>
#include <ctime>

#include  "ListaOrdenada.hpp"

using namespace std;

int main()
{
    srand(time(NULL));

    int min = 1, max = 100;
    int numeroAleatorio;

    cout << "========================================" << endl;
    cout << "   PRUEBA DE LISTA ORDENADA\n";
    cout << "========================================\n" << endl;

    try{
        ListaOrdenada<int> lista1;
        ListaOrdenada<int> lista2;

        for (int i = 0 ; i < 10 ; i++) {
            numeroAleatorio = min + rand() % (max - min + 1);
            lista1.Agregar(numeroAleatorio);

            numeroAleatorio = min + rand() % (max - min + 1);
            lista2.Agregar(numeroAleatorio);
        }

        lista1.Agregar(30);

        cout << "Lista1: " << lista1 << endl;
        cout << "Lista2: " << lista2 << endl;

        cout << "\nProbando la busqueda optimizada...\n";
        int numBuscado = 30;

        if (lista1.Buscar(numBuscado)) {
            cout << "¡Exito! El " << numBuscado << " si esta en la Lista 1.\n\n";
        }else {
            cout << "El " << numBuscado << " no se encuentra en la Lista 1.\n\n";
        }

        cout << "Eliminando el 30 de la Lista 1...\n";

        if (lista1.Eliminar(30)) {
            cout << "¡Exito! El 30 se eliminó de la Lista 1.\n\n";
        }else {
            cout << "El 30 no se encuentra en la Lista 1, no se pudo eliminar.\n\n";
        }

        cout << "Eliminando el 10 de la Lista 1...\n";
        if (lista1.Eliminar(10)) {
            cout << "¡Exito! El 10 se eliminó de la Lista 1.\n\n";
        }else {
            cout << "El 10 no se encuentra en la Lista 1, no se pudo eliminar.\n\n";
        }
        cout << "Lista 1 despues de borrar: " << lista1 << "\n\n";


        cout << "\nMEZCLANDO LAS LISTAS (Merge)...\n";
        ListaOrdenada<int> listaMezclada;

        listaMezclada = lista1.MezclarListas(lista1, lista2);

        cout << "Lista 1 original:  " << lista1 << "\n";
        cout << "Lista 2 original:  " << lista2 << "\n";
        cout << "LISTA MEZCLADA:    " << listaMezclada << "\n";
        cout << "Tamano total: " << listaMezclada.ObtenerTam() << " elementos.\n\n";

    }catch(const char* mensaje){
        cerr << "Error: " << mensaje << endl;
    }catch(const exception &error){
        cerr << "Error: " << error.what() << endl;
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }

    system("pause");
    return 0;
}
