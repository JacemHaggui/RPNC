# check if the source files are present in the working directory
test -f "rpn1.c" && echo "Exists" || echo "Does not exist"
test -f "rpn2.c" && echo "Exists" || echo "Does not exist"
test -f "rpn3.c" && echo "Exists" || echo "Does not exist"
test -f "rpn4.c" && echo "Exists" || echo "Does not exist"
test -f "rpn5.c" && echo "Exists" || echo "Does not exist"

# compile the source files to generate an executable file per source file
gcc rpn1.c -o rpn1
gcc rpn2.c -o rpn2
gcc rpn3.c -o rpn3
gcc rpn4.c -o rpn4
gcc rpn5.c -o rpn5