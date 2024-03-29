

test:
	g++ -Wall -ggdb3 -c src/Ellipsis.cpp -o objects/Ellipsis.o
	g++ -Wall -ggdb3 -c src/Polygone.cpp -o objects/Polygone.o
	g++ -Wall -ggdb3 -c src/Rectangle.cpp -o objects/Rectangle.o
	g++ -Wall -ggdb3 -c src/RegularPolygone.cpp -o objects/RegularPolygone.o
	g++ -Wall -ggdb3 -c src/Shape.cpp -o objects/Shape.o
	g++ -Wall -ggdb3 -c src/Stroke.cpp -o objects/Stroke.o
	g++ -Wall -ggdb3 -c src/Text.cpp -o objects/Text.o
	g++ -Wall -ggdb3 -c src/Grawink.cpp -o objects/Grawink.o
	g++ -Wall -ggdb3 -c src/mainTest.cpp -o objects/mainTest.o

	ar rcs libgraweditor.a objects/Ellipsis.o objects/Grawink.o objects/Polygone.o objects/Rectangle.o objects/RegularPolygone.o objects/Shape.o objects/Stroke.o objects/Text.o

	g++ -Wall -ggdb3 -o mybin.exe objects/mainTest.o -L. libgraweditor.a