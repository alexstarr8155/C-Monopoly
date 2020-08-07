CXX = g++
CXXLFAGS = -std=c++14 -Wall -MMD -g
OBJECTS = observer.o Subject.o Player.o Cell.o Property.o Improvable.o test.o 

EXEC = test
DEPENDS = ${OBJECTS:.o=.d}

.PHONY : all clean

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

-include ${DEPENDS}

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
