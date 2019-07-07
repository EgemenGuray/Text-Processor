CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -g -MMD 
EXEC = a4q5
OBJECTS = main.o echo.o textprocess.o decorator.o allcaps.o doublewords.o count.o dropfirst.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
