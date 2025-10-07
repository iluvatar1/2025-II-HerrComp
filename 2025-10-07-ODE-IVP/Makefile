
all: ivp_V1.x

%.x : %.cpp
	g++ -std=c++23 $< -o $@

#fig.pdf: plot.py data.txt 
#	python plot.py

#data.txt: sumas.x
#	./sumas.x


clean:
	rm -f *~ *.txt a.out *.x

