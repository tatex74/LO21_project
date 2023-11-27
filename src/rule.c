#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule.h"

// Crée une nouvelle règle vide
Rule *create_rule() {
    Rule *rule = (Rule*) malloc(sizeof(Rule));
    rule->premise = NULL; // Initialise la prémisse à NULL
    strcpy(rule->conclusion, ""); // Initialise la conclusion à une chaîne vide
    return rule;
}

Proposition *create_prop() {
    Proposition *new_prop = (Proposition*) malloc(sizeof(Proposition));
    new_prop->next = NULL;
    strcpy(new_prop->proposition, "");

    return new_prop;
}


// Ajoute une proposition à la prémisse d'une règle
Rule *add_prop_in_tail_of_rule(Rule *rule, char prop_string[]) {
    if (strlen(prop_string) > PROPOSISTION_BUFFER) {
        fprintf(stderr, "Error : cannot add rule, a rule must be less than 100 caracter.");
        return rule;
    }

    Proposition *new_prop = (Proposition*) malloc(sizeof(Proposition));
    if (new_prop ==  NULL) {
        fprintf(stderr, "Error : cannot add rule");
        return rule;
    }

    new_prop->next = NULL;
    strcpy(new_prop->proposition, prop_string);

    if (rule->premise ==  NULL) {
        rule->premise = new_prop; // Si la prémisse est vide, la nouvelle proposition devient la première
    } 
    else {
        Proposition *p = rule->premise;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_prop; // Ajoute la nouvelle proposition à la fin de la prémisse
    }

    return rule;
}

Proposition *add_prop_in_tail_of_list(Proposition *list, char prop_string[]) {
    Proposition *new_prop = (Proposition*) malloc(sizeof(Proposition));
    new_prop->next = NULL;
    strcpy(new_prop->proposition, prop_string);

    if (list == NULL) {
        return new_prop;
    }
    else {
        Proposition *p = list;

        while (p->next != NULL) {
            p = p->next;
        }

        p->next = (Proposition*) malloc(sizeof(Proposition));
        p->next->proposition;

        return list;
    }
}




// Vérifie si une proposition est dans la prémisse d'une règle (récursivement)
int contain_prop(Rule rule, char prop[]) {
    if (rule.premise == NULL) {
        return 0; // Si la prémisse est vide, la proposition n'est pas présente
    }
    else if (strcmp(prop, rule.premise->proposition)) {
        return 1; // Si la proposition est trouvée, retourne 1 (vrai)
    }
    else {
        rule.premise = rule.premise->next;
        return contain_prop(rule, prop); // Recherche récursive dans le reste de la prémisse
    }
}


int list_contain_prop(Proposition *list, char prop[]) {
    if (list == NULL) {
        return 0;
    }
    else if (strcmp(list->proposition, prop)) {
        return 1;
    }
    else {
        list = list->next;
        return list_contain_prop(list, prop);
    }
}


// Supprime une proposition de la prémisse d'une règle
Rule *remove_prop_of_rule(Rule *rule, char prop[]) {
    if (rule->premise == NULL) {
        return rule; // Si la prémisse est vide, rien à faire
    }
    else {
        if (strcmp(rule->premise->proposition, prop)) {
            Proposition *tmp = rule->premise->next;
            free(rule->premise);
            rule->premise = tmp; // Supprime la première proposition si c'est celle recherchée
        }
        else {
            Proposition *p = rule->premise;

            while (p->next != NULL && strcmp(p->next->proposition, prop) != 1) {
                p = p->next;
            }
            
            if (p->next != NULL) {
                Proposition *tmp = p->next->next;
                free(p->next);
                p->next = tmp; // Supprime une proposition dans le milieu ou à la fin de la prémisse
            }
        }
        return rule;
    }
}


Proposition *remove_prop_of_list(Proposition *list, char prop[]) {
    if (list == NULL) {
        return list; 
    }
    else {
        if (strcmp(list->proposition, prop)) {
            Proposition *tmp = list->next;
            free(list);
            list = tmp;
        }
        else {
            Proposition *p = list;

            while (p->next != NULL && strcmp(p->next->proposition, prop) != 1) {
                p = p->next;
            }
            
            if (p->next != NULL) {
                Proposition *tmp = p->next->next;
                free(p->next);
                p->next = tmp; // Supprime une proposition dans le milieu ou à la fin de la prémisse
            }
        }
        return list;
    }
}

// Supprime une règle, y compris sa prémisse, de la mémoire
void remove_rule(Rule *rule) {
    if (rule != NULL) { // Vérifie si la règle n'est pas NULL
        if (rule->premise != NULL) { // Vérifie si la prémisse de la règle n'est pas NULL
            Proposition *p = rule->premise;
            Proposition *tmp;
            while (p != NULL) {
                tmp = p->next;
                free(p); // Libère la mémoire de chaque proposition dans la prémisse
                p = tmp;
            }
        }

        free(rule); // Libère la mémoire de la règle elle-même
    }
}


