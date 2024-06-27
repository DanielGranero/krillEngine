#include <iostream>
#include "./include/RingBuffer.h"

using namespace KrillEngine;
int main() {
    RingBuffer pIn(64);
    for(float i = 1.0f; i <= pIn.capacity() + 2; i++){
        pIn.put(i);
    }
    std::cout<< "Tamaño: " << pIn.size() << std::endl;

    for(float i = 1.0f; i <= pIn.capacity(); i++){
        std::cout<< "Valor de la muestra: " << pIn.get() <<std::endl;
    }
    std::cout<< "Tamaño: " << pIn.size() << std::endl;
    return 0;
}
