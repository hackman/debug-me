All of the information in this repo is related to the:
  Debug me, if you can! Workshop.

This is a plan 

1. strace broken.bin
2. strace PHP-FPM with DB logging
3. ltrace Two different versions of the curl library 
  two php modules compiled with two different versions of the curl lib
4. gdb attach to a running process and modify a variale (loop.bin)
4.1. explain the importance of debug symbols and how are they separated
4.2. go trough the basic commands
5. gdb run a command
5.1. set breakpoint
6. gdb read a coredump 


strace ./broken.bin

strace -e trace=file ./broken.bin
strace -e status=failed ./broken.bin

strace examples:
 -f					- follow forks 
 -p					- attach to pid (can be specified multiple times)
strace -f $(ps ax|awk '/php-fpm/{print "-p "$1}')

 -o file			- I usually use -o trace.me :)
strace -o trace.me -f $(ps ax|awk '/php-fpm/{print "-p "$1}')

 -s NUM				- very usefull to show you more data out of the system calls
strace -s 200 -o trace.me -f $(ps ax|awk '/php-fpm/{print "-p "$1}')


 -P					- trace only syscalls accessing certain path
 -e trace=
		lstat       - specific syscall
		open,stat   - a list of syscalls
		file		- file related operations (open, stat, access, unlink, chmod, ...)
		process     - process related syscalls (clone, exec*, ...)
		network     - all network related syscalls (connect, ...)
 -e status=
		successful   Trace system calls that returned without an error code.  The -z option has the effect of status=successful.
		failed       Trace system calls that returned with an error code.  The -Z option has the effect of status=failed.
		unfinished   Trace system calls that did not return.  This might happen, for example, due to an execve call in a neighbour thread.
		unavailable  Trace system calls that returned but strace failed to fetch the error status.
		detached     Trace system calls for which strace detached before the return.

 --syscall-times (-T) usefull to observe system slowness
 -t					- print wall clock time 
 -tt				- print wall clock + microseconds
 -w					- shows you the time difference between each syscall

 -e inject=SYSCALL_SET:retval=42
	allows you to simulate issues or outcomes by replacing the actual syscal with -1 and returning a predefined value(42)
  you can also do other stuff, like:
    :signal=SIGSEGV
	:delay_enter=12
	:poke_enter=@argN=DATAN 
	:poke_exit=@argN=DATAN
	You can even limit it by number of matches of the SYSCALL_SET: first..last+step

ldd binary 

ltrace examples:

gdb examples:
  gdb CMD
  gdb CMD coredump
  gdb -p PID

  run
  break [file:][function|line]
  list [file:]function
  backtrace bt
  print p
  c
  next	n
  step	s
  .gdbinit examples
  disassemble 

