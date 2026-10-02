# Testes

## Teste 1 - Palavra do exemplo

Entrada:

```text
Palavra: coracao
SHIFT: 3
```

Resultado esperado segundo a regra `SHIFT + Fibonacci[i]`:

```text
gswgkle
```

## Teste 2 - Palavra curta

Entrada:

```text
Palavra: abc
SHIFT: 3
```

Fibonacci:

```text
1, 1, 2
```

Calculo:

```text
a + 3 + 1 = e
b + 3 + 1 = f
c + 3 + 2 = h
```

Resultado:

```text
efh
```

## Teste 3 - Volta do alfabeto

Entrada:

```text
Palavra: zzz
SHIFT: 3
```

Fibonacci:

```text
1, 1, 2
```

Calculo:

```text
z + 3 + 1 = d
z + 3 + 1 = d
z + 3 + 2 = e
```

Resultado:

```text
dde
```

Isso demonstra o funcionamento do `% 26`.
