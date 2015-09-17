OBJ = main.o quiz.o termsList.o fileIO.o random.o

test:	$(OBJ)
	g++ -o test $(OBJ)

main.o:	main.cpp
	g++ -c main.cpp

quiz.o:	quiz.cpp
	g++ -c quiz.cpp

termsList.o:	termsList.cpp
	g++ -c termsList.cpp

fileIO.o:	fileIO.cpp
	g++ -c fileIO.cpp

random.o:	random.cpp
	g++ -c random.cpp

clean:
	rm -f *.o
