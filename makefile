.PHONY: build

SOURCE = src/main.c ads_string.c

build:
	mkdir -p build
	gcc $(SOURCE) -o build/test
	./build/test
