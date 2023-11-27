#include <stdio.h>
#include <stdlib.h>
#include "rule.h"
#include "base.h"


// Crée une nouvelle base vide
Base *create_base() {
    Base *base = (Base*) malloc(sizeof(Base));
    base->head = NULL;
    return base;
} 


// Ajoute une règle à une base
Base *add_rule_in_tail(Base *base, Rule *rule) {
    if (base->head == NULL) {
        base->head = rule; // Si la base est vide, la nouvelle règle devient la première
    }
    else {
        Rule *p = base->head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = rule; // Ajoute la nouvelle règle à la fin de la base
    }

    return base;
}

// Supprime une base, y compris toutes ses règles, de la mémoire
void remove_base(Base *base) {
    if (base->head != NULL) { // Vérifie si la base n'est pas NULL
        Rule *p = base->head;
        Rule *tmp;
        
        while (p != NULL) {
            tmp = p->next;
            remove_rule(p); // Supprime chaque règle dans la base
            p = tmp;
        }   

        free(base); // Libère la mémoire de la base elle-même
    }
}
