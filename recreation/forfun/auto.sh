# !/bin/bash
javac IP.java
echo "enter lower limit"
read top
while [ $top -le 32 ]
do
  java IP $top
  let 'top++'
  echo
  echo
done
echo "finished"
