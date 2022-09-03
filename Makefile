all:
	gcc -c memlab.c -pthread
	ar -rcs libmemlab.a memlab.o
	gcc demo1.c -L. -lmemlab -pthread -o demo1
	gcc demo2.c -L. -lmemlab -pthread -o demo2
clean:
	rm memlab.o libmemlab.a demo1 demo2
