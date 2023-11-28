#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "rule.h"
#include "proposition.h"


Proposition *engine(Proposition *l_facts, Base *base);
Base *read_base_file(char filename[]);
Proposition *read_facts_file(char filename[]);
int is_valid_string_rule(char rule[]);
Base *add_rule_in_tail_string(Base *base, char rule[]);

#endif
