# Makefile 示例

# 编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra 

# 目标文件
TARGET = a 
SRCS = a.cpp
OBJS = $(SRCS:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# 编译源文件为目标文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(TARGET) $(OBJS)

# 伪目标
.PHONY: all clean

