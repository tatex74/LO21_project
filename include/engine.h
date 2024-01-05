#ifndef ENGINE_H
#define ENGINE_H

#define PROP_SIZE 128
#define MAX_PROP 20
#define LIGNE_MAX_SIZE (PROP_SIZE+2)*MAX_PROP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "base.h"
#include "rule.h"
#include "proposition.h"


Prop_List engine(Prop_List l_facts, Base base);
Base read_base_file(char filename[]);
Prop_List read_facts_file(char filename[]);

#endif
