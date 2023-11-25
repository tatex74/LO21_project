#include <stdio.h>
#include <stdlib.h>
#include "rule.h"
#include "base.h"


Base *create_base() {
    return (Base*) malloc(sizeof(Base));
} 


Base *add_rule_in_tail(Base *base, Rule *rule) {
    if (base == NULL) {
        base = rule;
    }
    else {
        Base p = base;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = rule;
    }

    return base;
}


void remove_base(Base *base) {
    if (base != NULL) {
        Rule *p = base;
        Rule *tmp;
        
        while (p != NULL) {
            tmp = p->next;
            remove_rule(p);
            p = tmp;
        }   

        free(base);
    }
}