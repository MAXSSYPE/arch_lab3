.PHONY: build

build:
	g++ ./main.cpp -o ak3

default_goal: build def
.PHONY: def
def:
	./ak3 -f -s -t -e

.PHONY: run

run:
	./ak3 -f


.DEFAULT_GOAL:=default_goal