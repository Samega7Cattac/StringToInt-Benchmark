OBJS = atoi.o from_chars.o

all: $(OBJS)
	$(CXX) atoi.o -o atoi $(CXXFLAGS)
	$(CXX) from_chars.o -o from_chars $(CXXFLAGS)

debug: CXXFLAGS += -g -sanatizer=address -DDEBUG
debug: all

clean:
	rm -f $(OBJS) atoi from_chars
