include=-Iraylib-5.0_linux_amd64/include -I.
lib=-Lraylib-5.0_linux_amd64/lib

default: run

main.o: main.c
	gcc -c main.c $(include)

gameobj.o: gameobj.c
	gcc -c gameobj.c $(include)

pong: main.o gameobj.o
	gcc -o pong main.o gameobj.o $(lib) -l:libraylib.a -lm

run: pong
	./pong

clean:
	rm -f *.o pong