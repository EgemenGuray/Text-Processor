#include "allcaps.h"


Allcaps::Allcaps(TextProcessor *component):Decorator(component){}

std::string Allcaps::getWord(){
    std::string str = component->getWord();
    for (auto & c: str) c = toupper(c);
    return str;
}

void Allcaps::setSource(std::istream *in) {
    
    component->setSource(in);
    
}
