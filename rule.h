#ifndef RULE_H
#define RULE_H

#define PROPOSISTION_BUFFER 100

typedef struct _Proposition {
    char proposition[PROPOSISTION_BUFFER];
    struct _Proposition *next;    
} Proposition;


typedef struct _Rule {
    Proposition *premise;
    char conclusion[PROPOSISTION_BUFFER];
    struct _Rule *next;
} Rule;

Rule *create_rule();
Rule *add_prop_in_tail(Rule *rule, char prop_string[]);
int contain_prop(Rule rule, char prop[]);
Rule *remove_prop(Rule *rule, char prop[]);
void remove_rule(Rule *rule);


#endif