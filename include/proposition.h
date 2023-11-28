#ifndef PROPOSISITION_H
#define PROPOSISITION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROPOSISTION_BUFFER 100

typedef struct _Proposition {
    char proposition[PROPOSISTION_BUFFER];
    struct _Proposition *next;    
} Proposition;

Proposition *create_prop();
Proposition *add_prop_in_tail_of_list(Proposition *list, char prop_string[]);
Proposition *remove_prop_of_list(Proposition *list, char prop[]);
int list_contain_prop(Proposition *list, char prop[]);
void print_proposition_list(Proposition *l_prop);

#endif