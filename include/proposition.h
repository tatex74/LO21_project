#ifndef PROPOSISITION_H
#define PROPOSISITION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROPOSISTION_BUFFER 100

typedef char* Proposition;

typedef struct prop_elem {
    Proposition prop;
    struct prop_elem *next;
} Prop_List_Element;

typedef Prop_List_Element* Prop_List;


Prop_List add_prop_in_tail_of_list(Prop_List list, Proposition prop);
Prop_List remove_prop_of_list(Prop_List list, Proposition prop);
int list_contain_prop(Prop_List list, Proposition prop);
void print_proposition_list(Prop_List list);
void free_prop_list(Prop_List list);

#endif