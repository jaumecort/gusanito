default: build

build:
	gcc -o snake *.c *.h bin/*.c bin/*.h

run: build
	./snake

