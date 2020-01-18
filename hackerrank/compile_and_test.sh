function compile_and_test() {
    program_name=$1
    g++ ${program_name}.cpp -o ${program_name} \
        && ls -1 inputs | while read input_file_name; do
            echo "-- Testing with input from '${input_file_name}':";
            ./${program_name} < inputs/${input_file_name};
        done
}

compile_and_test $@
