#include <iostream>
#include "src\Heaps\heap.h"

int main(){
    Heap min_h("min");
    
    min_h.push(3);
    min_h.push(4);
    min_h.push(5);
    min_h.push(2);
    
    min_h.print();
    
    Heap h("max");
    
    h.push(3);
    h.push(4);
    h.push(5);
    h.push(2);
    
    h.print();
    
    return 0;
}
