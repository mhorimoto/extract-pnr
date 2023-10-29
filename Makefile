LOAD=extract-pnr
OBJ=extract-pnr.o
SRC=extract-pnr.c

ALL: ${LOAD}

${OBJ}: ${SRC}

clean:
	-rm ${LOAD} ${OBJ} *~

install: ${LOAD}
	install -c ${LOAD} /usr/local/bin


