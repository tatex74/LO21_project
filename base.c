#include <stdio.h>
#include <stdlib.h>
#include "rule.h"
#include "base.h"


// Crée une nouvelle base vide
Base *create_base() {
    return (Base*) malloc(sizeof(Base));
} 


// Ajoute une règle à une base
Base *add_rule_in_tail(Base *base, Rule *rule) {
    if (base == NULL) {
        base = rule; // Si la base est vide, la nouvelle règle devient la première
    }
    else {
        Base p = base;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = rule; // Ajoute la nouvelle règle à la fin de la base
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
