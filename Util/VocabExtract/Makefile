OBJ = main.o Intstr.o Str_cell.o vocabextract.o Count_Review.o
OUT = main

all: $(OBJ)
	g++ -o $(OUT) $(OBJ)

main.o: main.cpp Intstr.h 
	g++ -c main.cpp

Intstr.o: Intstr.cpp Intstr.h Str_cell.h
	g++ -c Intstr.cpp

Str_Cell.o: Str_cell.cpp Str_cell.cpp
	g++ -c Str_cell.cpp

vocabextract.o: ./VocabExtract/vocabextract.cpp Intstr.h
	g++ -c ./VocabExtract/vocabextract.cpp

Count_Review.o: ./CountOnReview/Count_Review.cpp Intstr.h
	g++ -c ./CountOnReview/Count_Review.cpp

clear: 
	rm -f $(OUT) $(OBJ) 


