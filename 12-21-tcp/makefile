default: compile
compile runme: clientTCP.o
	@gcc -o runme clientTCP.o
clientTCP.o: clientTCP.c
	@gcc -c clientTCP.c -w
run: runme
	@./runme
clean:
	@rm *.o -f
	@rm -f runme