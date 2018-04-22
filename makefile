objects = treekea.o magatzem.o sala.o producte.o
test_dir = jocs_prova

DIFF = diff -y

CPP = g++
CPPFLAGS = --std=c++11 -g -Wall

TreeKEA: $(objects)
	$(CPP) $(CPPFLAGS) -o TreeKEA $(objects)

.PHONY: debug
debug: $(objects)
	$(CPP) $(CPPFLAGS) -c -DDEBUG treekea.cpp
	$(CPP) $(CPPFLAGS) -o TreeKEA $(objects)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(objects)

.PHONY: test
test: TreeKEA
	./TreeKEA <$(test_dir)/sample.inp >$(test_dir)/test.out
	$(DIFF) $(test_dir)/sample.cor $(test_dir)/test.out

doc: doxygen.config *.h *.cpp
	doxygen doxygen.config
	make -C doc/latex
