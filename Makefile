NAME=colcat
SRCS=colcat.c
CC=gcc
FLAGS= -g

all: 
	${CC} ${FLAGS} -o ${NAME} ${SRCS}
