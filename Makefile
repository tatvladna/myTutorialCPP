CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRC_DIR = src
UTILS_DIR = utils
SOURCES = main.cpp $(SRC_DIR)/beginner.cpp \
					$(SRC_DIR)/easy.cpp \
					$(SRC_DIR)/normal.cpp \
					$(SRC_DIR)/hard.cpp \
					$(SRC_DIR)/experienced.cpp \
					$(UTILS_DIR)/help.cpp
TARGET = myTasks
all: $(TARGET)
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
clean:
	rm -f $(TARGET)
