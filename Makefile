CXX = g++
CXXLFAGS = -std=c++14 -Wall -MMD -g
OBJECTS = Board.o BoardDisplay.o TempCell.o main.o

EXEC = test
DEPENDS = ${OBJECTS:.o=.d}

.PHONY : all clean

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

-include ${DEPENDS}

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
