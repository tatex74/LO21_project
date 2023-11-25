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


#endif