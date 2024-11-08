TEST   := 
DEBUG  := 

$(TEST):           
		/usr/bin/g++ $(TEST).cpp -o $(TEST).out
		./$(TEST).out

$(DEBUG):           
		/usr/bin/g++ -g -Wall $(DEBUG).cpp -o $(DEBUG).out
		/usr/bin/gdb ./$(DEBUG).out


clean:	
		\rm -rf *.out
