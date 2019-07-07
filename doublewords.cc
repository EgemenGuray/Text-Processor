#include "doublewords.h"
#include <sstream>

Doublewords::Doublewords(TextProcessor *component):Decorator(component){x=0;}

std::string Doublewords::getWord(){
    std::string str;
    if(x%2 == 0){
        str = component->getWord();
        rep = str;
        x++;
        return str;
    }else{
        x++;
        return rep;
    }
}

void Doublewords::setSource(std::istream *in) {
    
    component->setSource(in);
    
}
