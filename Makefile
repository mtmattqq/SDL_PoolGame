all:
	@echo "Compiling"
	g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2_image -lSDL2 

	@echo "-----------------------------"
	./main
	@echo "-----------------------------"