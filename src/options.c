#include "options.h"

void printHelp() {
    printf("Options:\n");
    printf("  --help  or -h  Print this help message\n");
    printf("  --base  or -b  File of the knowledge base\n");
    printf("  --facts or -f  File of facts\n");
}


Files_path get_paths(int argc, char *argv[]) {
    int opt = 0;

    Files_path paths;

	struct option opts[] = {
		{.name="help",.has_arg=0,.flag=0,.val='h'},
		{.name="base",.has_arg=1,.flag=0,.val='b'},
		{.name="facts",.has_arg=1,.flag=0,.val='f'},
		{.name=0,.has_arg=0,.flag=0,.val=0},
	};

	while((opt = getopt_long(argc, argv, "hb:f:", opts, NULL)) != -1) {
		switch (opt) {
			case 'h':
				printHelp();
				return (Files_path){NULL, NULL};
				break;
				
			case 'b':
				paths.base_file = (char*) malloc(sizeof(char));
                strcpy(paths.base_file, optarg);
				break;
				
			case 'f':
				paths.facts_file = (char*) malloc(sizeof(char));
				strcpy(paths.facts_file, optarg);
				break;
            default:
                printf("Error with argument");
                return paths;
		}
	}

	return paths;
}