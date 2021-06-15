default: build

build:
	gcc -o snake *.c *.h lib/*.c lib/*.h

run: build
	./snake

