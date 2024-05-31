# Définir le compilateur
CXX = g++

# Définir les options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17

# Nom de l'exécutable
TARGET = walkerran

# Fichiers source
SRCS = main.cpp walker.cpp

# Fichiers objets (générés à partir des fichiers source)
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut (cible par défaut)
all: $(TARGET)

# Comment créer l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system

# Comment compiler les fichiers source en fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers générés (objets et exécutables)
clean:
	rm -f $(OBJS) $(TARGET)

# Nettoyer tout (fichiers objets, exécutables, et fichiers de sauvegarde d'éditeurs)
distclean: clean
	rm -f *~ *.bak

.PHONY: all clean distclean
