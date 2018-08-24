QT += widgets

HEADERS       = include/plazzaGui.hpp

SOURCES       = main.cpp \
                plazza.cpp	\
		src/build.cpp	\
		src/getline.cpp	\
		src/father.cpp	\
		class/Child.cpp	\
		class/Error.cpp	\
		class/Mutex.cpp	\
		class/Parser.cpp	\
		class/ParserFile.cpp	\
		class/SafeQueue.cpp	\
		class/Socket.cpp	\
		class/Thread.cpp

QMAKE_CXXFLAGS += -std=c++14 -I./include -Wall -Wextra

LIBS += -lpthread

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/dialogs/findfiles
INSTALLS += target