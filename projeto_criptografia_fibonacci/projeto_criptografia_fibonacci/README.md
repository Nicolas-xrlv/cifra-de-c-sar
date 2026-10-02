# Projeto de Criptografia em Duas Camadas

Projeto desenvolvido em linguagem C para aplicar duas camadas de criptografia sobre uma palavra:

1. Camada 1: Cifra de Cesar com SHIFT fixo.
2. Camada 2: deslocamento dinamico utilizando a sequencia de Fibonacci.

O resultado e salvo em um arquivo `.txt` e cada execucao e registrada em um arquivo de log.

1. Regras do projeto

- A palavra deve possuir no maximo 15 letras.
- A palavra deve ser escrita sem acentos.
- A palavra deve ser escrita em letras minusculas.
- O programa utiliza a sequencia de Fibonacci.
- O SHIFT e informado pelo usuario.
- O resultado e gravado em `resultado/resultado_criptografia.txt`.
- O historico das execucoes e gravado em `logs/execucao.log`.

2. Funcionamento

O algoritmo utiliza duas camadas.

Camada 1 - Cifra de Cesar

Cada letra e convertida para uma posicao do alfabeto:

text
a = 0
b = 1
c = 2
...
z = 25

Depois, o valor do SHIFT e somado.

Exemplo com SHIFT 3:

text
a -> d
b -> e
c -> f

A formula utilizada e:

text
(letra + SHIFT) % 26

O `% 26` garante que, ao ultrapassar a letra `z`, o algoritmo volte ao inicio do alfabeto.

3. Camada 2 - Fibonacci

Depois da Cifra de Cesar, e aplicado um deslocamento adicional baseado na sequencia:

text
1, 1, 2, 3, 5, 8, 13, 

Para cada letra, utiliza-se um valor diferente da sequencia.

A formula final e:

text
(letra + SHIFT + Fibonacci[i]) % 26

 4. Exemplo

Entrada:

text
Palavra: coracao
SHIFT: 3
Sequencia: Fibonacci

Fibonacci utilizada:

text
1, 1, 2, 3, 5, 8, 13

A transformacao pode ser entendida como:

text
c + 3 + 1 = g
o + 3 + 1 = s
r + 3 + 2 = w
a + 3 + 3 = g
c + 3 + 5 = k
a + 3 + 8 = l
o + 3 + 13 = e


Resultado:
text
g s w g k l e

 5. Estrutura do projeto

text
projeto_criptografia_fibonacci/
│
├── src/
│   └── main.c
│
├── resultado/
│   └── resultado_criptografia.txt
│
├── logs/
│   └── execucao.log
│
├── docs/
│   └── algoritmo.md
│
└── README.md

6. Como compilar
Abra o terminal dentro da pasta do projeto e execute:

bash
gcc src/main.c -o criptografia

Depois:
 Windows

bash
.\criptografia.exe

7. Exemplo de execucao

text
   -------CRIPTOGRAFIA EM DUAS CAMADAS-------

Digite a palavra (ate 15 letras, sem acentos): coracao
Digite o SHIFT: 3


Palavra original: coracao
SHIFT: 3
Sequencia: Fibonacci
Palavra criptografada: gswgkle

Arquivo resultado_criptografia.txt: OK
Arquivo execucao.log: OK

Execucao finalizada.

8. Arquivo de resultado

Depois da execucao, o programa cria/atualiza:

text
resultado/resultado_criptografia.txt


Exemplo:

text
Palavra original: coracao
Palavra codificada: gswgkle
SHIFT: 3
Tipo: Fibonacci
Letras: 7

9. Arquivo de log

O arquivo:
text
logs/execucao.log

mantem o historico das execucoes.

Exemplo:
text
Data/Hora: 01/10/2026 15:00:00
Palavra original: coracao
SHIFT: 3
Sequencia: Fibonacci
Valores utilizados: 1, 1, 2, 3, 5, 8, 13
Palavra codificada: gswgkle

O log utiliza o modo `a` do `fopen`, portanto novas execucoes sao adicionadas ao final do arquivo.


10. Principais funcoes

`gerarFibonacci()`

Gera os valores da sequencia de Fibonacci de acordo com a quantidade de letras da palavra.

`palavraValida()`

Verifica se a palavra possui entre 1 e 15 letras e se todos os caracteres sao letras minusculas.

`criptografar()`

Aplica as duas camadas de criptografia.

`salvarResultado()`

Cria o arquivo `resultado_criptografia.txt` e salva o resultado.

`salvarLog()`

Registra data, hora, palavra, SHIFT, sequencia e resultado da execucao.


11. Tecnologias utilizadas

- Linguagem C
- Git
- GitHub
- Arquivos `.txt`
- Arquivo de log `.log`