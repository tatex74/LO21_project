#include <stdio.h>
#include "base.h"
#include "engine.h"
#include "proposition.h"
#include "options.h"

int main(int argc, char *argv[]) {

    Files_path *paths;
    if ((paths = get_paths(argc, argv)) == NULL) {
        return 1;
    }
    
    Base *base = read_base_file(paths->base_file);
    Proposition *facts = read_facts_file(paths->facts_file);

    Proposition *new_facts = engine(facts, base);

    print_proposition_list(new_facts);

    return 0;
}