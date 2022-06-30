CXX = g++
CXXFLAGS = -Wall
LDLIBS = -lGL -lglut -lGLU
BINS = teste

# Criar executaveis a partir de objetos usando compilador de C++
%: %.o
	$(CXX) $(LDFLAGS) $@.o $(LOADLIBES) $(LDLIBS) -o $@

all: $(BINS)

clean:
	rm -f *.o $(BINS)

