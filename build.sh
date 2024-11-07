#! /bin/bash

echo If compilation fails, make sure you have 'cc' installed or manually compile src/main.c

cc -Wall -o src/RNG/makerandom src/RNG/makerandom.c 
src/RNG/makerandom

cc -Wall -o numbersorter src/main.c

echo Try ./numbersorter random_list sorted_list
