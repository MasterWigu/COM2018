 #!/bin/bash  


for arg in "$@"
do
	echo ""
  	echo "Running $arg"
  	../diy "${arg%.*}".diy
done

#rm *.bla
#rm bla