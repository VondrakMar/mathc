build:
	gcc src/main.c src/basis_functions.c src/linalg.c src/util.c src/machine_learning.c -lm -o mathc.out

clean:
	rm mathc.out

