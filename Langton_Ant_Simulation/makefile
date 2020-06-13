#makefile for Project1 by Darwin Yee
#Adapted from Lecture: Makefiles module
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = Menu.o LangtonAntMain.o InputValidation2.o Board.o Ant.o

SRCS = Menu.cpp LangtonAntMain.cpp InputValidation2.cpp Board.cpp Ant.cpp

HEADERS = Menu.hpp InputValidation2.hpp Board.hpp Ant.hpp

OUTPUT = Project1

#target: dependencies
#	rule to build
#

${OUTPUT}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${OUTPUT}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${OUTPUT}