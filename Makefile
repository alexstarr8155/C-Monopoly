CXX = g++
CXXLFAGS = -std=c++14 -Wall -MMD -g
OBJECTS = Player.o Cell.o Property.o Improvable.o Residence.o Gym.o GoToTims.o Tuition.o Tims.o SLC.o GooseNesting.o NeedlesHall.o CollectOSAP.o CoopFee.o Board.o BoardDisplay.o controller.o

EXEC = test
DEPENDS = ${OBJECTS:.o=.d}

.PHONY : all clean

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

-include ${DEPENDS}

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
