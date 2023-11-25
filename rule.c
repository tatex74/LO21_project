#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule.h"

Rule* create_rule() {
    Rule *rule = (Rule*) malloc(sizeof(Rule));
    rule->premise = NULL;
    strcpy(rule->conclusion, "");
    return rule;
}


Rule* add_prop_in_tail(Rule *rule, char prop_string[]) {
    if (strlen(prop_string) > PROPOSISTION_BUFFER) {
        fprintf(stderr, "Error : cannot add rule, a rule must be less than 100 caracter.");
        return rule;
    }

    Proposition *new_prop = (Proposition*) malloc(sizeof(Proposition));
    new_prop->next = NULL;
    strcpy(rule->premise->proposition, prop_string);

    if (rule->premise ==  NULL) {
        rule->premise = new_prop;
    } 
    else {
        Proposition *p = rule->premise;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_prop;
    }

    return rule;
}


int contain_prop(Rule rule, char prop[]) {
    if (rule.premise == NULL) {
        return 0;
    }
    else if (strcmp(prop, rule.premise->proposition)) {
        return 1;
    }
    else {
        rule.premise = rule.premise->next;
        return contain_prop(rule, prop);
    }
}


Rule* remove_prop(Rule *rule, char prop[]) {
    if (rule->premise == NULL) {
        return rule;
    }
    else {
        if (strcmp(rule->premise->proposition, prop)) {
            Proposition *tmp = rule->premise->next;
            free(rule->premise);
            rule->premise = tmp;
        }
        else {
            Proposition *p = rule->premise;

            while (p->next != NULL && strcmp(p->next->proposition, prop) != 1) {
                p = p->next;
            }
            
            if (p->next != NULL) {
                Proposition *tmp = p->next->next;
                free(p->next);
                p->next = tmp;
            }
        }
    }
}


