build:
	gcc main.c -o main

run:
	gcc main.c -o main
ifeq ($(OS),Windows_NT)
	main
else
	./main
endif