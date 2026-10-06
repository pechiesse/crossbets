Crossbet
ps 2026.2 crossbots - Programacao
Projeto sem fins financeiros


1. Pre-requisitos:
    - Git, para baixar o projeto.
    - Um compilador de C, o gcc:
    - Windows: MinGW ou TDM-GCC (confira com gcc --version).
    - Linux: sudo apt install gcc (Ubuntu/Debian).
    - macOS: xcode-select --install.

2. Baixar o projeto
    git clone <URL-DO-REPOSITORIO>
    cd <NOME-DA-PASTA>

3. Compilar
   - windows
          mkdir output
          gcc -Wall -Wextra -g3 main.c cassino.c cacaniquel.c roleta.c dados.c -o output\main.exe
   - Linux e macOS
         mkdir output
         gcc -Wall -Wextra -g3 main.c cassino.c cacaniquel.c roleta.c dados.c -o output\main.exe

4. Executar
   - Windows
         .\output\main.exe
   - Linux e macOS
         ./output/main
                   
