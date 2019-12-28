shell: Shell.o builtinf.o
	gcc Shell.o builtinf.o -o shell

Shell.o: Shell.c builtinf.h
	gcc -c builtinf.h Shell.c

builtin.o: parser.c exe_shell.c init_shell.c rnmocc.c shell_run_time.c trivialf.c shell_read.c
	gcc -c parser.c exe_shell.c init_shell.c rnmocc.c shell_run_time.c trivialf.c shell_read.c

clean:
	rm *.o shell
