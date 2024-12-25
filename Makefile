CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRC_DIR = src
SOURCES = main.cpp $(SRC_DIR)/people.cpp $(SRC_DIR)/help.cpp
TARGET = myPeople
all: $(TARGET)
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
clean:
	rm -f $(TARGET)
