#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include "rule.h"

typedef struct _Base {
    Rule *head;
} Base;

Base *create_base();
Base *add_rule_in_tail(Base *base, Rule *rule);
void remove_base(Base *base);
Base *remove_rule_of_base(Base *base, Rule *rule);


#endif