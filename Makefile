CXX_FLAGS = -Wall -g -Wextra -std=c++0x
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: war-server war-client

clean:
	rm -f war-server war-client






