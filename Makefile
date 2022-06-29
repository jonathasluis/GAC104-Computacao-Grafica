CXX = g++
CXXFLAGS = -Wall
LDLIBS = -lGL -lglut -lGLU
BINS = teste

# Criar executaveis a partir de objetos usando compilador de C++
%: %.o
	$(CXX) $(LDFLAGS) $@.o $(LOADLIBES) $(LDLIBS) -o $@

all: $(BINS)

camera.orig: camera.orig.o transformacao.o ponto.o
	$(CXX) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

movelight: movelight.o
	$(CXX) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f *.o $(BINS)

