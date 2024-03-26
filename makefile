# Définition des variables
CXX = g++                              # Compilateur C++
CXXFLAGS = -Wall -Wextra -std=c++11    # Options de compilation
SRC_DIR = src                          # Répertoire des fichiers source (.cpp)
INCLUDE_DIR = include                  # Répertoire des fichiers d'en-tête (.hpp)
BUILD_DIR = build                      # Répertoire de construction (fichiers objets)
TARGET = mon_programme                         # Nom de l'exécutable à générer



test:
	g++ -c src/Ellipsis.cpp -o objects/Ellipsis.o
	g++ -c src/Polygone.cpp -o objects/Polygone.o
	g++ -c src/Rectangle.cpp -o objects/Rectangle.o
	g++ -c src/RegularPolygone.cpp -o objects/RegularPolygone.o
	g++ -c src/Shape.cpp -o objects/Shape.o
	g++ -c src/Stroke.cpp -o objects/Stroke.o
	g++ -c src/Text.cpp -o objects/Text.o
	g++ -c src/Grawink.cpp -o objects/Grawink.o
	g++ -c src/mainTest.cpp -o objects/mainTest.o

	ar rcs libgraweditor.a objects/Ellipsis.o objects/Grawink.o objects/Polygone.o objects/Rectangle.o objects/RegularPolygone.o objects/Shape.o objects/Stroke.o objects/Text.o

	g++ -o mybin.exe objects/mainTest.o -L. libgraweditor.a