CXX = g++
CXXLFAGS = -std=c++14 -Wall -MMD -g
OBJECTS = Board.o BoardDisplay.o Cell.o Property.o Improvable.o Gym.o Residence.o NeedlesHall.o SLC.o GoToTims.o Tims.o CoopFee.o GooseNesting.o Tuition.o CollectOSAP.o Player.o main.o

EXEC = test
DEPENDS = ${OBJECTS:.o=.d}

.PHONY : all clean

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

-include ${DEPENDS}

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

