global   main
	  extern    printf
main:
	  mov   edi, formatting
	  xor   eax, eax
	  call  printf
	  mov   eax, 0
	  ret
formatting: db `Hello, Holberton\n`,0


