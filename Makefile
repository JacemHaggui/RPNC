# Makefile

.PHONY: all build test clean

all: build test clean

build:
	@bash build.sh

test:
	@bash test.sh

clean:
	@bash clean.sh