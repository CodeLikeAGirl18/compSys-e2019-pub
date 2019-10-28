gcc=gcc -g -Werror -Wpedantic -Wall -o
src=homework_problem_8-24.c
executable=homework_problem_8-24


compile: $(executable)

run: compile
	./$(executable)

$(executable): $(src)
	$(gcc) $(executable) $(src)


clean:
	rm -f $(executable)
