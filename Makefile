market : market.c product.o manager.o
	gcc -o market market.c product.o manager.o
clean :
	rm *.o market
