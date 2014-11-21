compile:
	clang++ -o bin/pacman src/**.cc -std=c++11 -lSDL2 -lSDL2_image

run:
	bin/pacman
