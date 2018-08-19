CXX_FLAGS = -Wall -g -Wextra -std=c++0x
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: war-server war-client

war-server: war-server.cpp map_data.o rules.o

war-client: war-client.cpp rules.o

clean:
	rm -f war-server war-client *.o

