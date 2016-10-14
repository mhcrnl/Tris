all: TrisTest

clean:
	rm -f TrisTest

TrisTest: TrisTest.c
	cc -o $@ $@.c
