HEADERS = node.h LList.h dataPair.h HashTable.h
OBJECTS = main.o node.o LList.o dataPair.o HashTable.o
EXEC = Project3


#build executable program
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
#build objective files from source files
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
#clean up the mess
clean:
	rm -i `find ./ -type f -executable`
	rm -i *.o
#run the executable	
run: $(EXEC)
	./$(EXEC)

