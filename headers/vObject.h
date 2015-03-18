#include <typeinfo>
template <class T>
class vObject {
protected:
    void* valor;    //Deberia ser vRef si no me equivoco
public:

    void operator=(T dato){
        valor = (void*)dato;
    }

    void operator=(vObject dato){
        valor = dato.valor;
    }

    bool operator==(vObject dato){
        return valor == dato.valor;
    }

    char const getInstance(void){
        return (char const) typeid(valor).name();
    }

};
