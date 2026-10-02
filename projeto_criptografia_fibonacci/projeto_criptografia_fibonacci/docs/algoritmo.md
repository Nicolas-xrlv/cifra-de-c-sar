# Algoritmo

## Entrada

1. Ler uma palavra com no maximo 15 letras.
2. Ler o valor do SHIFT.
3. Gerar a quantidade de termos de Fibonacci necessaria.

## Processamento

Para cada letra:

1. Converter a letra para um valor entre 0 e 25.
2. Somar o SHIFT.
3. Aplicar `% 26`.
4. Somar o termo correspondente da sequencia de Fibonacci.
5. Aplicar `% 26` novamente.
6. Converter o valor de volta para uma letra.

Formula:

```text
resultado[i] = (palavra[i] - 'a' + SHIFT + Fibonacci[i]) % 26
```

## Saida

1. Mostrar a palavra criptografada.
2. Gravar o resultado em `resultado/resultado_criptografia.txt`.
3. Registrar a execucao em `logs/execucao.log`.
