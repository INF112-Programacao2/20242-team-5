# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11

# File lists
SOURCES = main.cpp Condicional.cpp Golpe.cpp Habilidade.cpp Item.cpp ModificaEst.cpp Pokemon.cpp Tipo.cpp Treinador.cpp
HEADERS = Condicional.hpp Golpe.hpp Habilidade.hpp Habilidades.hpp Item.hpp Items.hpp ModificaEst.hpp Pokemon.hpp Tipo.hpp Treinador.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = pokemon_game

# Main target
all: $(EXECUTABLE)

# Linking
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Compilation rule for each .cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Run the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)
