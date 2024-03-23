# Définition des variables
CXX = g++                              # Compilateur C++
CXXFLAGS = -Wall -Wextra -std=c++11    # Options de compilation
SRC_DIR = src                          # Répertoire des fichiers source (.cpp)
INCLUDE_DIR = include                  # Répertoire des fichiers d'en-tête (.hpp)
BUILD_DIR = build                      # Répertoire de construction (fichiers objets)
TARGET = mon_programme                         # Nom de l'exécutable à générer

# Recherche de tous les fichiers source (.cpp) dans SRC_DIR et ses sous-répertoires
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Conversion des fichiers source en fichiers objets dans BUILD_DIR
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Règle pour construire l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Règle pour construire les fichiers objets
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Création du répertoire de construction s'il n'existe pas
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)
