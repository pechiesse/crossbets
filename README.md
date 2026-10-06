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
         gcc -Wall -Wextra -g3 main.c cassino.c cacaniquel.c roleta.c dados.c -o output/main.exe

4. Executar
   - Windows
         .\output\main.exe
   - Linux e macOS
         ./output/main

Explicacao dos jogos
Roleta
    Numero de 0 a 36
    Voce tem 4 opcao de aposta
        1 - Numero 0 - 36 (35x)
        2 - Cor: Vermelho / Preto (1x)
        3 - Par ou impar (1x)
        4 - Duzias (2x)
    Sendo os numeros vermelhos: 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36
    
Caca-niquel
        3 slots
        cada slot com valor de 1 a 7
        Se conseguir 3 numeros iguas voce ganha

Dados
    Dois dados sao rolados e a soma e o resultado
        Voce tem 3 opcoes de aposta
                1 - Menor que 7 (1x)
                2 - Exatamente 7 (4x)
                3 - Maior que 7 (1x)
                   
