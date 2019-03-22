#!/bin/bash  

cd ..
make
cd tests
for arg in "$@"
do
	echo ""
  	echo "Running $arg"
  	../diy < "${arg%.*}".in > "${arg%.*}".out.temp
  	diff -q "${arg%.*}".out "${arg%.*}".out.temp
done

echo 
rm *.out.temp
cd ..
make clean