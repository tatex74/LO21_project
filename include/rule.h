#ifndef RULE_H
#define RULE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proposition.h"

// Structure représentant une règle dans la base de connaissances
typedef struct _Rule {
    Proposition *premise; // Prémisse de la règle (liste de propositions)
    char conclusion[PROPOSISTION_BUFFER]; // Conclusion de la règle
    struct _Rule *next; // Pointeur vers la règle suivante dans la base de connaissances
} Rule;

Rule *create_rule();
Rule *add_prop_in_tail_of_rule(Rule *rule, char prop_string[]);
int contain_prop(Rule rule, char prop[]);
Rule *remove_prop_of_rule(Rule *rule, char prop[]);
void remove_rule(Rule *rule);



#endif
