num1=$(find $1 -name "*$2"|wc -l)
echo $num1
if (($num1==0)); then
	echo Не существует файла с заданным типом
	exit
fi
if (($num1%2==0)); then
	a=$(ps|wc -l)
	echo Число активных процессов - $((a-2))
else
	sleep 7
fi


# ./test1.sh /c/Users/vasil/desktop/лабы txt
#	$1 -- это первый вводимый параметр(C:\Users\vasil\Desktop\лабы; вводится путь), 
#	$2 -- формат файла(.txt)