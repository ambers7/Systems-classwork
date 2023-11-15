default: compile
notDefault:
	@echo "No arguments runs the first recipe no matter what you call it"
compile runme: main.o 
	@gcc -o runme main.o 
main.o: main.c
	@gcc -c main.c
run: runme
	@./runme $(ARGS)
clean:
	@rm *.o -f
	@rm -f runme