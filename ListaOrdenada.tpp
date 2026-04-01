
//***********************************

template <typename T>
ListaOrdenada<T>::ListaOrdenada()
{
    numElem = 0;
    primero = nullptr;
    ultimo = nullptr;
}

//***********************************

template <typename T>
ListaOrdenada<T>::~ListaOrdenada()
{
    Vaciar();
}

//***********************************

template <typename T>
ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada& lista)
{
    numElem = 0;
    primero = nullptr;
    ultimo = nullptr;
    *this = lista;
}

//***********************************

template <typename T>
ListaOrdenada<T>& ListaOrdenada<T>::operator=(const ListaOrdenada& lista)
{
    if(this == &lista) return *this;

    Vaciar();

    if (lista.EstaVacia()) return *this;

    Elemento *visitado = lista.primero;

    while(visitado != nullptr) {
        Agregar(visitado->valor);
        visitado = visitado->siguiente;
    }

    return *this;
}

//***********************************

template <typename T>
void ListaOrdenada<T>::Agregar(T valor)
{
    try{

        if(EstaVacia()){
            Elemento *nuevo = new Elemento(valor);
            primero = nuevo;
            ultimo = nuevo;
            ++numElem;
            return;
        }

        Elemento *aux = primero;
        while(aux != nullptr && aux->valor < valor){
            aux = aux->siguiente;
        }

        if(aux == nullptr){ // Si es el elemento mas grande
            Elemento *nuevo = new Elemento(valor, ultimo, nullptr);
            ultimo->siguiente = nuevo;
            ultimo = nuevo;

        }else if(aux == primero){
            Elemento *nuevo = new Elemento(valor, nullptr, primero);
            primero->anterior = nuevo;
            primero = nuevo;

        }else{
            Elemento *nuevo = new Elemento(valor, aux->anterior, aux);
            aux->anterior->siguiente = nuevo;
            aux->anterior = nuevo;

        }

        ++numElem;
    }catch(std::bad_alloc&){
        throw ListaNoMemoria();
    }

}

//***********************************

template <typename T>
bool ListaOrdenada<T>::Eliminar(T valor)
{
    Elemento *visitado = primero;

    while (visitado != nullptr && visitado->valor < valor) {
        visitado = visitado->siguiente;
    }

    if (visitado == nullptr || visitado->valor != valor) { // Reccorió todo y no se encontró
        return false;
    }

    if (visitado == primero && visitado == ultimo) { // Se elimina el unico valor

        primero = nullptr;
        ultimo = nullptr;

    } else if (visitado == primero) { // Se elimina el primer valor

        primero = visitado->siguiente;
        primero->anterior = nullptr;

    } else if (visitado == ultimo) { // Se elimina el ultimo valor

        ultimo = visitado->anterior;
        ultimo->siguiente = nullptr;

    } else { // Se elimina un valor intermedio

        visitado->anterior->siguiente = visitado->siguiente;
        visitado->siguiente->anterior = visitado->anterior;

    }

    delete visitado;
    --numElem;
    return true;
}

//***********************************

template <typename T>
bool ListaOrdenada<T>::Buscar(T valor) const
{
    Elemento *visitado = primero;

    while (visitado != nullptr && visitado->valor < valor) {
        visitado = visitado->siguiente;
    }

    return (visitado != nullptr && visitado->valor == valor);
}

//***********************************

template <typename T>
int ListaOrdenada<T>::ObtenerTam() const
{
    return numElem;
}

//***********************************

template <typename T>
bool ListaOrdenada<T>::EstaVacia() const
{
    return numElem == 0;
}

//***********************************

template <typename T>
void ListaOrdenada<T>::Vaciar()
{
    while (!EstaVacia()) Eliminar(primero->valor);
}

//***********************************

template <typename T>
void ListaOrdenada<T>::Imprimir() const
{
    if(EstaVacia()){
        std::cout << "[ ]";
        return;
    }

    Elemento *visitado = primero;
    std::cout << "[ ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->siguiente;
    }

    if(!EstaVacia()) std::cout << "\b\b ]";
}

//***********************************

template <typename T>
void ListaOrdenada<T>::ImprimirReversa() const
{
    if(EstaVacia()){
        std::cout << "[ ]" << std::endl;
        return;
    }

    Elemento *visitado = ultimo;
    std::cout << "[ ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->anterior;
    }

    if(!EstaVacia()) std::cout << "\b\b ]";
}

//***********************************

template <typename T>
ListaOrdenada<T> ListaOrdenada<T>::MezclarListas(const ListaOrdenada& lista1, const ListaOrdenada& lista2)
{
    ListaOrdenada<T> nuevaLista;

    Elemento *visit1 = lista1.primero;
    Elemento *visit2 = lista2.primero;

    // Mientras ambas listas tengan elementos, los hacemos competir
    while (visit1 != nullptr && visit2 != nullptr) {

        if (visit1->valor <= visit2->valor) {
            // Si el de la lista 1 es menor o igual, lo metemos
            nuevaLista.Agregar(visit1->valor);
            visit1 = visit1->siguiente;
        } else {
            // Si el de la lista 2 es menor, lo metemos a él
            nuevaLista.Agregar(visit2->valor);
            visit2 = visit2->siguiente;
        }
    }

    // Una de las dos listas se vació primero.
    // Vaciamos lo que haya sobrado de la lista 1 (si es que sobró algo)
    while (visit1 != nullptr) {
        nuevaLista.Agregar(visit1->valor);
        visit1 = visit1->siguiente;
    }

    // Vaciamos lo que haya sobrado de la lista 2 (si es que sobró algo)
    while (visit2 != nullptr) {
        nuevaLista.Agregar(visit2->valor);
        visit2 = visit2->siguiente;
    }

    return nuevaLista;
}

//***********************************
// Constructor de Elemento
//***********************************

template <typename T>
ListaOrdenada<T>::Elemento::Elemento(T v, Elemento *ant /*=nullptr*/, Elemento *sig /*=nullptr*/) : valor(v), anterior(ant), siguiente(sig) {}

//***********************************
// Implementaci�n de las clases excepciones
//***********************************

template <typename T>
ListaOrdenada<T>::ListaVacia::ListaVacia() throw() {}

//***********************************

template <typename T>
ListaOrdenada<T>::ListaNoMemoria::ListaNoMemoria() throw(){}

//***********************************

template <typename T>
ListaOrdenada<T>::ListaIndice::ListaIndice() throw(){}

//***********************************

template <typename T>
const char *ListaOrdenada<T>::ListaVacia::what() const throw()
{
    return "La lista se encuentra vac\241a.";
}

//***********************************

template <typename T>
const char *ListaOrdenada<T>::ListaNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
}

//***********************************

template <typename T>
const char *ListaOrdenada<T>::ListaIndice::what() const throw()
{
    return "\326ndice fuera de rango.";
}




template <typename T>
std::ostream& operator<<(std::ostream& salida, const ListaOrdenada<T>& lista)
{
    lista.Imprimir();
    return salida;
}