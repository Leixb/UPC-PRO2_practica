objects = program.o magatzem.o sala.o inventari.o
test_dir = jocs_prova

DIFF = diff -y

CPP = g++
CPPFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

.PHONY: debug clean test profile release upload

program.exe: $(objects)
	$(CPP) $(CPPFLAGS) -o program.exe $(objects)

%.o: %.cc
	$(CPP) $(CPPFLAGS) -c $< -o $@

debug: CPPFLAGS += -g -DDEBUG
debug: clean program.exe

profile: CPPFLAGS += -pg
profile: clean program.exe
	./program.exe <$(test_dir)/sample.inp
	gprof -a program.exe >analysis.txt

release: CPPFLAGS+=-O3
release: clean program.exe

test: program.exe
	./program.exe <$(test_dir)/sample.inp | diff - -y $(test_dir)/sample.cor $(test_dir)/test.out

doc: doxyfile *.hh *.cc
	doxygen doxyfile
	#make -C doc/latex

html.zip: doc
	zip html.zip doc/html -r

clean:
	-rm -r $(objects)

practica.tar: *.cc *.hh makefile html.zip
	tar -cvf practica.tar html.zip makefile *.cc *.hh

upload: test practica.tar
	jutge upload --code X73158_ca --compiler MakePRO2 practica.tar --check --annotation "Uploaded by jutge_cli. MD5: $(shell md5sum practica.tar) commit: $(shell git rev-parse HEAD)"

