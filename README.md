crossbet
ps 2026.2 crossbots

Requisitos:
    Windows
        tdm-gcc https://jmeubank.github.io/tdm-gcc/download/
        git


Para compilar:
1 - baixe os arquivos do github
2 - No cmd
    git clone https://github.com/pechiesse/crossbets.git   
    mkdir output
    gcc -Wall -Wextra -g3 main.c cassino.c cacaniquel.c roleta.c -o output\main.exe
    cd output\main.exe
3 - Toda a execucao é feita no terminal 
    cd 