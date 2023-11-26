OBJ = main.o engine.o base.o rule.o

main : ${OBJ}
	gcc -o $@ $^

main.o : main.c engine.c base.c rule.c
	gcc -c $<

engine.o : engine.c
	gcc -c $<

base.o : base.c
	gcc -c $<

rule.o : rule.c
	gcc -c $<

