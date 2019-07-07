#ifndef _ALLCAPS_H_
#define _ALLCAPS_H_

#include "textprocess.h"
#include "decorator.h"
#include <string>

class Allcaps: public Decorator {
    
public:
    Allcaps(TextProcessor *component);
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
