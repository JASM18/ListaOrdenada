#ifndef LISTAORDENADA_HPP_INCLUDED
#define LISTAORDENADA_HPP_INCLUDED

#include <iostream>
#include <exception>

template <typename T>
class ListaOrdenada {

public:
    ListaOrdenada();

    ~ListaOrdenada();

    ListaOrdenada(const ListaOrdenada& lista);

    ListaOrdenada& operator=(const ListaOrdenada& lista);

    void Agregar(T valor);

    bool Eliminar(T valor);

    bool Buscar(T valor) const;

    int ObtenerTam() const;

    bool EstaVacia() const;

    void Vaciar();

    void Imprimir() const;

    void ImprimirReversa() const;

    ListaOrdenada MezclarListas(const ListaOrdenada& lista1, const ListaOrdenada& lista2);


    /**
     * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando se intenta acceder o extraer de una cola vac&iacute;a.
     */
    class ListaVacia : public std::exception {
    public:
        /** \brief Constructor por default de la excepci&oacute;n ColaVacia.
         */
        ListaVacia() throw();

        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una lista vac&iacute;a.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    /**
    * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando ocurren fallos de reserva de memoria.
    */
    class ListaNoMemoria : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n ListaNoMemoria.
         */
        ListaNoMemoria() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando no haya memoria disponible.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    /**
    * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando el cliente intenta acceder a indices no disponibles
    */
    class ListaIndice : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n ListaNoMemoria.
         */
        ListaIndice() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando el cliente intente acceder a indices no disponibles.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

private:

    int numElem = 0;        ///< Cantidad de elementos guardados en la lista.

    /**
    * \brief Descripci&oacute;n de la clase/struct: Estructura interna para representar un nodo doblemente enlazado.
    */
    struct Elemento {
        T valor;                            ///< Dato almacenado en el nodo.
        Elemento *anterior, *siguiente;     ///< Punteros a los elementos anterior y siguiente.

        /** \brief Constructor de la estructura Elemento.
        * \param v Dato a almacenar.
        * \param ant Puntero al elemento anterior.
        * \param sig Puntero al elemento siguiente.
        */
        Elemento(T v, Elemento *ant = nullptr, Elemento *sig = nullptr);
    };

    Elemento *primero = nullptr;            ///< Puntero al primer elemento de la lista.
    Elemento *ultimo = nullptr;             ///< Puntero al &uacute;ltimo elemento de la lista.

};

template <typename T>
std::ostream& operator<<(std::ostream& salida, const ListaOrdenada<T>& lista);

#include "ListaOrdenada.tpp"

#endif // LISTAORDENADA_HPP_INCLUDED
