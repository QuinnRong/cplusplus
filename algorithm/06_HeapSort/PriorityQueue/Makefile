TARGET = demo

CXX = g++

CXXFLAGS += -I../include

SRCDIR = ./
SRCS = $(wildcard $(SRCDIR)*.cpp)

OBJDIR = ./bin/
OBJS =$(addprefix $(OBJDIR), $(notdir $(patsubst %.cpp, %.o, $(SRCS))))
ifeq ($(wildcard $(OBJDIR)), )
$(shell mkdir -p $(OBJDIR))
endif

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.Phony: clean
clean:
	rm -rf $(TARGET) bin