#include "base.h"


// Crée une nouvelle base vide
Base create_base() {
    Base new_base = NULL;
    return new_base;
} 


// Ajoute une règle à une base
Base add_rule_in_tail(Base base, Rule rule) {

    Rule_List_Element *new_elem = (Rule_List_Element*) malloc(sizeof(Rule_List_Element));
    if (new_elem == NULL) {
        fprintf(stderr, "Error : Rule_List_Element* allocation\n");
        return base;
    }

    new_elem->rule = rule;
    new_elem->next = NULL;

    if (base == NULL) {
        base = new_elem; // Si la base est vide, la nouvelle règle devient la première
    }
    else {
        Rule_List_Element *p_elem = base;
        
        while (p_elem->next != NULL) {
            p_elem = p_elem->next;
        }
        p_elem->next = new_elem; // Ajoute la nouvelle règle à la fin de la base

    }

    return base;
}

Rule_List_Element* head_rule(Base base) {
    if (base != NULL) {
        return base;
    }
    else {
        return NULL;
    }
}

// Supprime une base, y compris toutes ses règles, de la mémoire
void free_base(Base base) {
    Rule_List_Element *p = base;
    Rule_List_Element *tmp;
    
    while (p != NULL) {
        tmp = p->next;
        free_rule_list_element(p); // Supprime chaque règle dans la base
        p = tmp;
    }
}

void print_base(Base base) {
    if (base != NULL) {
        Rule_List_Element *p = base;
        while (p != NULL) {
            if (p->rule.premise != NULL) {
                print_proposition_list(p->rule.premise);
            }
            p = p->next;
        }
    }
    printf("\n");
}





