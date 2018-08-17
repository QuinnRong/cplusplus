TARGET = demo

CONFIG_FILE := Makefile.config
ifeq ($(wildcard $(CONFIG_FILE)), )
$(error $(CONFIG_FILE) not found. See $(CONFIG_FILE).example.)
endif
include $(CONFIG_FILE)

CXX = g++

ifeq ($(DEBUG), 1)
	CXXFLAGS = -g -O0
else
	CXXFLAGS = -O3
endif

CXXFLAGS += -Wall -std=c++11 \
	-Iinclude \
	-I/usr/local/include

LIBS = \
	-Llib \
	-L/usr/local/lib \
	-L/usr/lib \
	-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

SRCDIR = ./src/
SRCS = $(wildcard $(SRCDIR)*.cpp)

OBJDIR = ./bin/
OBJS =$(addprefix $(OBJDIR), $(notdir $(patsubst %.cpp, %.o, $(SRCS))))
ifeq ($(wildcard $(OBJDIR)), )
$(shell mkdir -p $(OBJDIR))
endif

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ $(LIBS) 

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean
clean:
	-rm -rf $(TARGET) bin