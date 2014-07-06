bin/proj4test : *.c bin makefile
	g++ *.c /usr/local/lib/libproj.a -o bin/proj4test

bin : 
	mkdir bin

