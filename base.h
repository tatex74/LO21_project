#ifndef BASE_H
#define BASE_H

#include "rule.h"

typedef Rule* Base;

Base *create_base();
Base *add_rule_in_tail(Base *base, Rule *rule);


#endif