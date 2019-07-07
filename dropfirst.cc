#include "dropfirst.h"

Dropfirst::Dropfirst(TextProcessor *component, int n): Decorator{component}, n{n}{}


void Dropfirst::setSource(std::istream *inp){
    component->setSource(inp);
}

std::string Dropfirst::getWord(){
    
    std::string s = component->getWord();
    std::string ret = "";
    for (int i = 0; i < s.length(); i++){
        if(i >= n){
            ret += s.at(i);
        }
    }
    if(ret == ""){
        throw 2;
    }
    return ret;
}
