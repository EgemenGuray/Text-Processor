#include "count.h"


Count::Count(TextProcessor *component, char c):Decorator(component), z{c} {x=0;}

std::string Count::getWord(){
    
    std::string str = component->getWord();
    
    std::string dummy = "";
    
    for(int i = 0; i < str.length(); i++){
        
        if(str.at(i) == z){
            x++;
            dummy += std::to_string(x);
        }else{
            dummy += str.at(i);
        }
        
        
    }
    
    
    return dummy;
    
}

void Count::setSource(std::istream *in) {
    
    component->setSource(in);
    
}
