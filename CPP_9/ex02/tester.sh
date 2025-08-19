#!/bin/bash

echo "---- Testeo numero negativo ----"
./PmergeMe 12 55 1 99 122 "-9" 0 756
echo

echo "---- Testeo letras ----"
./PmergeMe 12 55 1 99 122 AA 0 756
echo

echo "---- Testeo caracteres invalidos ----"
./PmergeMe 12 55 1 99 122 123a 0 756
echo

echo "---- Testeo too big ----"
./PmergeMe 12 55 1 99 122 2147483650 0 756
echo

echo "---- Testeo de 15 números ----"
./PmergeMe $(shuf -i 1-100 -n 15)
echo

echo "---- Testeo de 30 números ----"
./PmergeMe $(shuf -i 1-100 -n 30)
echo

echo "---- Testeo de 100 números ----"
./PmergeMe $(shuf -i 1-1000 -n 100)
echo

echo "---- Testeo de 1000 números ----"
./PmergeMe $(shuf -i 1-10000 -n 1000)
echo

echo "---- Testeo de 2000 números ----"
./PmergeMe $(shuf -i 1-10000 -n 2000)
echo

echo "---- Testeo de 3000 números ----"
./PmergeMe $(shuf -i 1-10000 -n 3000)
