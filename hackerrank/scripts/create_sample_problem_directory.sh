#!/bin/sh

program_name=$1

mkdir -p -m 775 ${program_name}

java_program_name=`echo "$program_name" | awk -F"-" '{for(i=1;i<=NF;i++){$i=toupper(substr($i,1,1)) substr($i,2)}} 1' OFS=""`

touch ${program_name}/${program_name}.cpp
touch ${program_name}/${java_program_name}.java
touch ${program_name}/${program_name}.py

mkdir -p -m 775 ${program_name}/inputs
touch ${program_name}/inputs/input-1.in

echo 'public class '${java_program_name}' {
  public static void main(String[] args) {
    System.out.printf("'${java_program_name}' java program\n");
  }
}' >> ${program_name}/${java_program_name}.java

echo '#include<iostream>

int main() {
    std::cout << "'${program_name}' cpp program" << std::endl;
    return 0;
}' >> ${program_name}/${program_name}.cpp
echo "#!/usr/bin/env python

print('${program_name} python program')" >> ${program_name}/${program_name}.py
