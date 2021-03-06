//
// Created by roberto on 17/04/15.
//

#include "../Headers/proof.h"

/** Prueba un vString
 */
void pruebaString(){
    std::cout << "INICIA LA PRUEBA DE VSTRING, SE CREARA UNO, SE LE AGREGARAN ELEMENTOS Y SE BORRARA, PRESIONE ENTER" << std::endl;
    std::cin.get();
    vString a = vString("hola ");
    std::cout<<"impresion vString: "<<!a<<std::endl;
    a+="a ";
    std::cout<<"impresion vString: "<<!a<<std::endl;
    a+="todos";
    std::cout<<"impresion vString: "<<!a<<std::endl;
    --a;
    std::cout<<"impresion vString borrado: "<<!a<<std::endl;
    std::cout << "PRUEBA FINALIZADA, PARA CONTINUAR PRESIONE ENTER" << std::endl;
    std::cin.get();
}

/**Inserta elementos en el arbol utilizado para metadata
 */
void pruebaTree(){
    Tree<int>* prueba = static_cast<Tree<int>*>(malloc(sizeof(Tree<int>)));
    new(prueba) Tree<int>();
    std::cout << "INICIA LA PRUEBA DEL ARBOL, SE INSERTARAN 10000 ELEMENTOS, PRESIONE ENTER" << std::endl;
    std::cin.get();
    for(int i=0; i<NUMBER_OF_CONTAINERS_TO_FILL; i++) prueba->insertElement(i,i);
    std::cout << "INSERCION FINALIZADA, SE IMPRIMIRAN LOS DATOS, PRESIONE ENTER" << std::endl;
    std::cin.get();
    for(int i=0; i<NUMBER_OF_CONTAINERS_TO_FILL; i++) std::cout<< *prueba->searchElement(i) <<std::endl;
    free(prueba);
    std::cout << "FIN DE LA PRUEBA, PARA CONTINUAR PRESIONE ENTER" << std::endl;
    std::cin.get();
}

/** Prueba un vType mediante la incersion de varias instancias en un arreglo
 * @param vType: clase a probar
 * @param TypeToCastIndex: analogo de c++
 * @param int cantidadDeElementos: elementos a insertar
 * @param float offset: numero que se suma al indice del for
 */
template <class TypeToCast> void prueba_vNumber_con_vArray(int cantidadDeElementos, float offset){
    vArray<vNumber<TypeToCast>> arreglo = vArray<vNumber<TypeToCast>>(cantidadDeElementos);
    std::cout << "SE PROBARA UN vTYPE, SE INSERTARAN " << cantidadDeElementos << " ELEMENTOS" <<
            " EN UN vARRAY SE IMPRIMIRA, PRESIONE ENTER" << std::endl;
    std::cin.get();
    for(int i = 0; i<cantidadDeElementos; i++){
        *(arreglo[i]) = (TypeToCast)(i+offset);
    }
    for(int i = 0; i<cantidadDeElementos; i++) {
        std::cout<< !*(arreglo[i])<<std::endl;
    }
    std::cout << "FIN DE LA PRUEBA, PARA CONTINUAR PRESIONE ENTER" << std::endl;
    std::cin.get();
};

/** Inicia las pruebas
 */
void begin(){
    //pruebaTree();
    prueba_vNumber_con_vArray<int>(SIZE_OF_ARRAY_AND_LIST, NULL_OFFSET);
    prueba_vNumber_con_vArray<float>(SIZE_OF_ARRAY_AND_LIST, FLOAT_OFFSET);
    prueba_vNumber_con_vArray<long>(SIZE_OF_ARRAY_AND_LIST, LONG_OFFSET);
    prueba_vNumber_con_vArray<char>(SIZE_OF_CHAR_ARRAY, FIRST_ASCII_CHAR);
    //pruebaString();
    std::cout << "FIN DE LAS PRUEBAS, PARA INICIAR EL JUEGO PRESIONE ENTER" << std::endl;
    std::cin.get();
}