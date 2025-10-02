
fig.pdf: plot.py data.txt 
	python plot.py

sumas.x: sumas.cpp
	g++ -std=c++23 sumas.cpp -o sumas.x

data.txt: sumas.x
	./sumas.x


# %.x : %.cpp
# 	g++ -std=c++23 $< -o $@