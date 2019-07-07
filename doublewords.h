#ifndef _DOUBLEWORDS_H_
#define _DOUBLEWORDS_H_

#include "textprocess.h"
#include "decorator.h"
#include <string>
#include <sstream>

class Doublewords: public Decorator {
    int x;
    std::string rep;
    
public:
    Doublewords(TextProcessor *component);
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};


#endif
