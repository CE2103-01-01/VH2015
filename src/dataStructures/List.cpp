//
// Created by alex on 19/03/15.
//

using namespace std;

// Constructor por defecto
template<typename T>
List<T>::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}
// Insertar al inicio
template<typename T>
void List<T>::add_head(T data_)
{
    node<T> *new_node = new node<T> (data_);
    node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->nextNode = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->nextNode;
        }
    }
    m_num_nodes++;
}
// Insertar al final
template<typename T>
void List<T>::add_end(T data_)
{
    node<T> *new_node = new node<T> (data_);
    node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = new_node;
    }
    m_num_nodes++;
}
// Eliminar todos los nodos
template<typename T>
void List<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}
// Buscar el dato de un nodo
template<typename T>
void List<T>::search(T data_)
{
    node<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->data == data_) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->nextNode;
        cont++;
    }

    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}
// Eliminar por data del nodo
//
template<typename T>
void List<T>::del_by_data(T data_)
{
    node<T> *temp = m_head;
    node<T> *temp1 = m_head->nextNode;

    int cont = 0;

    if (m_head->data == data_) {
        m_head = temp->nextNode;
    } else {
        while (temp1) {
            if (temp1->data == data_) {
                node<T> *aux_node = temp1;
                temp->nextNode = temp1->nextNode;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->nextNode;
            temp1 = temp1->nextNode;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}
// Eliminar por posición del nodo
template<typename T>
void List<T>::del_by_position(int pos)
{
    node<T> *temp = m_head;
    node<T> *temp1 = temp->nextNode;

    if (pos < 1 || pos > m_num_nodes) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        m_head = temp->nextNode;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                node<T> *aux_node = temp1;
                temp->nextNode = temp1->nextNode;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->nextNode;
            temp1 = temp1->nextNode;
        }
    }
}