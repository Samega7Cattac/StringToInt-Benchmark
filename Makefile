OUTPUT = benchmark
N_TIMES = 10000000

OBJS = benchmark.o
#atoi.o from_chars.o strtol.o istringstream.o stoi.o
# TEST_STRING = 123456789

all: $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

debug: CXXFLAGS += -g -fsanitize=address -Wall
debug: all

run:
	./$(OUTPUT) $(N_TIMES)

clean:
	rm -f *.o $(OUTPUT)
