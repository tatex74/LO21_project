#include "options.h"

void printHelp() {
    printf("Usage: program_name [OPTIONS]\n");
    printf("Options:\n");
    printf("  -h      Print this help message\n");
    printf("  --base  file of the knowledge base\n");
    printf("  --facts  file of facts\n");
}


Files_path *get_paths(int argc, char *argv[]) {
    int opt = 0;

    Files_path *paths = (Files_path*) malloc(sizeof(Files_path));

	struct option opts[] = {
		{.name="help",.has_arg=0,.flag=0,.val='h'},
		{.name="base",.has_arg=1,.flag=0,.val='b'},
		{.name="facts",.has_arg=1,.flag=0,.val='f'},
		{.name=0,.has_arg=0,.flag=0,.val=0},
	};

	while((opt = getopt_long(argc, argv, "", opts, NULL)) != -1) {
		switch (opt) {
			case 'h':
				printHelp();
				break;
				
			case 'b':
                strcpy(paths->base_file, optarg);
				break;
				
			case 'f':
				strcpy(paths->facts_file, optarg);
				break;
		}
	}

	return paths;
}