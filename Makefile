CXX = clang++
CXXFLAGS = -std=c++20 -Wall -I./utility -I./shingling -I./encoder
SRCS = main.cc \
  		shingling/shingling.cc \
			utility/inputHandler.cc \
			encoder/encoder.cc
TARGET = LSH
TEXTS = $(wildcard text/*.txt)
SHING_SIZE ?= 2

run: $(TARGET)
	./$(TARGET) $(SHING_SIZE) $(words $(TEXTS)) $(TEXTS)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean clear begone:
	rm -f $(TARGET)