TEST   := 
DEBUG  := 

$(TEST):           
		/usr/bin/g++ -std=c++0x -Wall $(TEST).cpp -o $(TEST).out
		./$(TEST).out

$(DEBUG):           
		/usr/bin/g++ -std=c++0x -g -Wall  $(DEBUG).cpp -o $(DEBUG).out
		/usr/bin/gdb ./$(DEBUG).out


clean:	
		\rm -rf *.out
