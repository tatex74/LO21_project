#ifndef RULE_H
#define RULE_H

#define PROPOSISTION_BUFFER 100

// Structure représentant une proposition dans une règle
typedef struct _Proposition {
    char proposition[PROPOSISTION_BUFFER];
    struct _Proposition *next;    
} Proposition;


// Structure représentant une règle dans la base de connaissances
typedef struct _Rule {
    Proposition *premise; // Prémisse de la règle (liste de propositions)
    char conclusion[PROPOSISTION_BUFFER]; // Conclusion de la règle
    struct _Rule *next; // Pointeur vers la règle suivante dans la base de connaissances
} Rule;

Rule *create_rule();
Rule *add_prop_in_tail(Rule *rule, char prop_string[]);
int contain_prop(Rule rule, char prop[]);
Rule *remove_prop(Rule *rule, char prop[]);
void remove_rule(Rule *rule);


#endif
