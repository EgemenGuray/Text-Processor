#ifndef _DROPFIRST_H_
#define _DROPFIRST_H_

#include "textprocess.h"
#include "decorator.h"
#include <string>

class Dropfirst: public Decorator {
    int n;
public:
    Dropfirst(TextProcessor *component, int n);
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};


#endif
