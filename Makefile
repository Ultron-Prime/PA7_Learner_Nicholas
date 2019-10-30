TARGET = proj7
CXX = g++
CXX_FLAGS = -Wall

all: $(TARGET)

$(TARGET): $(TARGET).o MyString.o
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp MyString.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp MyString.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

MyString.o: MyString.cpp MyString.h
	$(CXX) $(CXX_FLAGS) -c MyString.cpp

clean:
	-rm -f *.o
	-rm -f $(TARGET)
