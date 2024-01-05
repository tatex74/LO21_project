#ifndef RULE_H
#define RULE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "proposition.h"


typedef struct {
    Prop_List premise;
    Proposition conclusion;
} Rule;


typedef struct rule_elem {
    Rule rule;
    struct rule_elem *next;
} Rule_List_Element;


Rule create_rule();
Rule add_prop_in_tail_of_rule(Rule rule, Proposition prop);
Rule create_rule_conclusion(Rule rule, Proposition conclusion);
int rule_contain_prop(Rule rule, Proposition prop);
Rule remove_prop_of_rule(Rule rule, Proposition prop);
int is_empty_premise(Rule rule);
Prop_List_Element* head_of_premise(Rule rule);
Proposition conclusion(Rule rule);

int is_valid_string_rule(char rule[]);
Rule create_rule_from_string(char *string_rule);

void free_rule_list_element(Rule_List_Element *rule_elem);



#endif
