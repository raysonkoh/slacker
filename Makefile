CXX = g++
CXXFLAGS = -std=c++17 -o slacker
MAC_FRAMEWORK = -framework Carbon

all:
	${CXX} ${CXXFLAGS} ${MAC_FRAMEWORK} mouse.cc main.cc 
