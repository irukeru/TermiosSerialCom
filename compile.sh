g++ -O2 -c TermiosSerialCom.cpp
g++ -O2 -c example.cpp
g++ -o example example.o TermiosSerialCom.o

rm TermiosSerialCom.o
rm example.o
