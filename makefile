.PHONY : all	clean

DEST	:= /usr/local/include/
MASTER	:= nish.h
HEADERS	:= nish_headers/

all:
	cp $(MASTER) $(DEST)$(MASTER)
	cp -r $(HEADERS) $(DEST)$(HEADERS)