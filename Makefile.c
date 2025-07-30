all:run

clear:
  rm -rf shell

shell:clear
      gcc -g -o shell main.c shell.c 

removo:
  rm -f *.o
  
run:shell removo 
    ./main
