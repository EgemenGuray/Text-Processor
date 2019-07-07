#ifndef _COUNT_H_
#define _COUNT_H_

#include "textprocess.h"
#include "decorator.h"
#include <string>

class Count: public Decorator {
    char z;
    int x;
public:
    Count(TextProcessor *component , char c);
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
