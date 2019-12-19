OBJS = atoi.o from_chars.o strtol.o istringstream.o stoi.o

all: $(OBJS)
	$(CXX) atoi.o -o atoi $(CXXFLAGS)
	$(CXX) from_chars.o -o from_chars $(CXXFLAGS)
	$(CXX) strtol.o -o strtol $(CXXFLAGS)
	$(CXX) istringstream.o -o istringstream $(CXXFLAGS)
	$(CXX) stoi.o -o stoi $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $@ $< $(CXXFLAGS)

debug: CXXFLAGS += -g -sanatizer=address -DDEBUG -Wall
debug: all

run:
	./atoi
	./from_chars
	./strtol
	./istringstream
	./stoi

clean:
	rm -f $(OBJS) atoi from_chars strtol istringstream stoi
