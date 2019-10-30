# !/bin/bash
javac IP.java
echo Foo
echo netmask needed to accomodate 15 IPs is
log=$(bc -l <<< "l(15)/l(2)")
num1=32
temp=$(python -c "from math import ceil; print ceil($log)")
num2=${temp%.*}

res="$(($num1-$num2))"
echo /$res
java IP $res
printf "\n\n\n\n"

echo Bar
echo netmask needed to accomodate 20 IPs is
log=$(bc -l <<< "l(20)/l(2)")
num1=32
temp=$(python -c "from math import ceil; print ceil($log)")
num2=${temp%.*}

res="$(($num1-$num2))"
echo /$res
java IP $res
printf "\n\n\n\n"




echo Baz
echo netmask needed to accomodate 15 IPs is
log=$(bc -l <<< "l(15)/l(2)")
num1=32
temp=$(python -c "from math import ceil; print ceil($log)")
num2=${temp%.*}

res="$(($num1-$num2))"
echo /$res
java IP $res
printf "\n\n\n\n"



echo Qux
echo netmask needed to accomodate 42 IPs is
log=$(bc -l <<< "l(42)/l(2)")
num1=32
temp=$(python -c "from math import ceil; print ceil($log)")
num2=${temp%.*}

res="$(($num1-$num2))"
echo /$res
java IP $res
printf "\n\n\n\n"

echo Corge
echo netmask needed to accomodate 60 IPs is
log=$(bc -l <<< "l(60)/l(2)")
num1=32
temp=$(python -c "from math import ceil; print ceil($log)")
num2=${temp%.*}

res="$(($num1-$num2))"
echo /$res
java IP $res
printf "\n\n\n\n"

echo Grault
echo netmask needed to accomodate 50 IPs is
log=$(bc -l <<< "l(50)/l(2)")
num1=32
temp=$(python -c "from math import ceil; print ceil($log)")
num2=${temp%.*}

res="$(($num1-$num2))"
echo /$res
java IP $res
printf "\n\n\n\n"

echo Garply
echo netmask needed to accomodate 10 IPs is
log=$(bc -l <<< "l(10)/l(2)")
num1=32
temp=$(python -c "from math import ceil; print ceil($log)")
num2=${temp%.*}

res="$(($num1-$num2))"
echo /$res
java IP $res
printf "\n\n\n\n"
