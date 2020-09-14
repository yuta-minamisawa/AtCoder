#!/bin/sh

#ARRAY=(a b c d e f)
echo contestname:
read dirname

if [ ! -d ./$dirname ]; then
  mkdir $dirname
fi

cd $dirname

cp ../download.sh download.sh

echo filenames:
read FILES

echo $FILES | xargs mkdir
echo $FILES | xargs -n 1 sh -c 'cp ../tmplate.cpp ./$0/$0.cpp'
echo $FILES | xargs -n 1 sh -c 'cp ../check.sh ./$0/check.sh'
echo $FILES | xargs -n 1 sh -c 'code ./$0/$0.cpp'


# for var in ${ARRAY[*]}
# do
#   if [ ! -d ./$1/$var ]; then
#     mkdir $1/$var
#   fi
#   cp tmplate.cpp $1/$var/$var.cpp
# done
