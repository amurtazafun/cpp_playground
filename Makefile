TEST   := 
DEBUG  := 

$(TEST):           
		/usr/bin/g++ -std=c++0x $(TEST).cpp -o $(TEST).out
		./$(TEST).out

$(DEBUG):           
		/usr/bin/g++ -std=c++0x -ggdb $(DEBUG).cpp -o $(DEBUG).out
		/usr/bin/gdb ./$(DEBUG).out


clean:	
		\rm -rf *.out
