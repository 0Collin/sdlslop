# /bin/bash

mkdir ./backups/$(date "+%Y-%m-%d-%T")
cp -r ./src/* ./backups/$(date "+%Y-%m-%d-%T")/
g++ -g -std=c++20 ./src/*.cpp -I./include -o ./bin/prog -lSDL3 -ldl
