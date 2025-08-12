all: build

build:
	cc main.c -o srchit -lX11 

install: build
	install srchit /usr/bin/

uninstall:
	rm /usr/bin/srchit
