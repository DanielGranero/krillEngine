CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = krillEngine
INCLUDE = -I./include
SOURCE_PATH = ./src/
SOURCES = main.cpp $(SOURCE_PATH)RingBuffer.cpp
HEADERS = SineWaveGenerator.h WavFile.h dr_wav.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
