#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include "rule.h"

typedef Rule_List_Element* Base;

Base create_base();
Base add_rule_in_tail(Base base, Rule rule);
Rule_List_Element* head_rule(Base base);

void free_base(Base base);
void print_base(Base base);

#endif