#include "decorator.h"
#include "textprocess.h"


Decorator::Decorator(TextProcessor *component): component{component} {}

Decorator::~Decorator() { delete component; }
