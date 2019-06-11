#
# TODO:
#
 
CC := g++
# CC := clang
SRCDIR := src
BUILDDIR := build
BINDIR := bin
TARGET := bin/runner
TESTDIR := test

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
#LIB :=
INC := -I include
$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@mkdir -p $(BINDIR)
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

tests:
	@mkdir -p $(BINDIR)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/user.cpp -o $(BUILDDIR)/user.o
	$(CC) $(CFLAGS) $(INC) -c $(TESTDIR)/user_test.cpp -o $(BUILDDIR)/test.o
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/data.cpp -o $(BUILDDIR)/data.o
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/balance.cpp -o $(BUILDDIR)/balance.o
	$(CC) $(CFLAGS) $(INC) -c $(SRCDIR)/Input.cpp -o $(BUILDDIR)/Input.o
	$(CC) $(BUILDDIR)/test.o $(BUILDDIR)/user.o $(BUILDDIR)/data.o $(BUILDDIR)/Input.o $(BUILDDIR)/balance.o -o $(BINDIR)/test -lboost_unit_test_framework

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(BINDIR)"; $(RM) -r $(BUILDDIR) $(BINDIR)

.PHONY: clean

