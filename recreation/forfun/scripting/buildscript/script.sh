#!/bin/bash

#reset environment
echo cleaning build folder
cd build && rm * && ls && cd ..
rm build.tar

echo 'Hello Human!'

#extract the version number from changelog.md
head -n 1 ./source/changelog.md > temp
read firstline < temp
#echo 1st line is: $firstline
read -a splitfirstline <<< $firstline
version=${splitfirstline[1]}
echo version is: $version

#prompt user to continue or not
echo 'do you want to continue? (1 continue, 0 exit, 2 robust)'
read versioncontinue
regex='^[0-9]+'
if ! [[ $versioncontinue =~ $regex ]]
then
	echo not a number
elif [ $versioncontinue -eq 1 ]
then
	echo OK
  
  #copy every file from source to build
  files=source/*
  echo files: $files
  i=1
  for file in $files
  do
  	#ignore secretinfo.md
    if ! [[ $file =~ 'secretinfo.md' ]]
    then
      cp $file ./build
      echo file $i: $file copied
    fi
    let 'i++'
  done
 	
  #move into the build dir and list files
  cd build
  echo the contents of build $version are
  ls
  
  #move out of the build dir when done
  cd ..
  
elif [ $versioncontinue -eq 0 ]
then
	echo please come back when ur ready
elif [ $versioncontinue -eq 2 ]
then
	echo youre using the robust script
	echo it compresses the build dir
  echo it uses emoji
  echo and git commits the changes at the end
  
  #change 42 to XX in secretinfo.md
  #cp ./source/* ./build
  cd source && cp * ../build && cd .. 
  echo psuedo-encrypt secretinfo.md
  sed 's/42/XX/g' build/secretinfo.md

  
  #compress the build directory
  echo compressing ./build
  tar cvf build.tar build
  
  
  #echo an emoji to the terminal
  # declare an array of emoji
	EMOJIS=(😺 😸 😹 😻 😼 😽 🙀 😿 😾 🗿)

	# select a random element from the EMOJIS set
	SELECTED_EMOJI=${EMOJIS[$RANDOM % ${#EMOJIS[@]}]};
  echo youre doing great ${SELECTED_EMOJI}
  


  
else
	echo bad input
fi


