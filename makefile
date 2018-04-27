objects = treekea.o magatzem.o sala.o producte.o
test_dir = jocs_prova

DIFF = diff -y

CPP = g++
CPPFLAGS = --std=c++11 -Wall

.PHONY: debug clean test profile release

TreeKEA: $(objects)
	$(CPP) $(CPPFLAGS) -o TreeKEA $(objects)

%.o: %.cc
	$(CPP) $(CPPFLAGS) -c $< -o $@

debug: CPPFLAGS += -g -DDEBUG
debug: clean TreeKEA

profile: CPPFLAGS += -pg
profile: clean TreeKEA
	./TreeKEA <$(test_dir)/sample.inp
	gprof -a TreeKEA >analysis.txt

release: CPPFLAGS+=-O3
release: clean TreeKEA

test: TreeKEA
	./TreeKEA <$(test_dir)/sample.inp >$(test_dir)/test.out
	$(DIFF) $(test_dir)/sample.cor $(test_dir)/test.out

doc: doxyfile *.hh *.cc
	doxygen doxyfile
	make -C doc/latex

clean:
	-rm -r $(objects)
