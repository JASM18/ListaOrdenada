
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
void ListaOrdenada<T>::Agregar(T valor)
{
    try{

        if(EstaVacia()){
            Elemento *nuevo = new Elemento(valor);
            primero = neuvo;
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

    while (valor != visitado->valor && visitado != nullptr){
        visitado = visitado->siguiente;
    }



}
