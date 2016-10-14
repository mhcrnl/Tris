all: TrisTest

clean:
	rm -f *.o
	rm -f TrisTest

.o:
	cc -c $@.c

TrisTest: TrisTest.c TrisImpl.o
	cc -o $@ $@.c *.o

test: TrisTest
	./TrisTest
