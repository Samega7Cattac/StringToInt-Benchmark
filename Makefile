OBJS = stoi.o from_chars.o

all: $(OBJS)
	$(CXX) stoi.o -o stoi $(CXXFLAGS)
	$(CXX) from_chars.o -o from_chars $(CXXFLAGS)

debug: CXXFLAGS += -g -sanatizer=address -DDEBUG
debug: all

clean:
	rm -f $(OBJS) stoi from_chars
