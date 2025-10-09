
DEPS=particle.o main_visual_md.o
LIBS=-lsfml-window -lsfml-graphics -lsfml-system
FLAGS=-std=c++23 -O2

all: md_sfml.x

md_sfml.x: $(DEPS)
	g++ $(FLAGS) -g $^ $(LIBS) -o $@

%.o : %.cpp
	g++ -c $(FLAGS) $< -o $@

#%.x : %.cpp
#	g++ -std=c++23 $< -o $@

#fig.pdf: plot.py data.txt 
#	python plot.py

#data.txt: sumas.x
#	./sumas.x


clean:
	rm -f *~ *.txt a.out *.x *.o

