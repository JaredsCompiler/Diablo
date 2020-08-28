# Regexes List

## Control Flow

- &
- &&
- |
- ||

```
((\&?\&)|(\||\|\|))
```

- if(match)

```
(?P<branch>(if?\selse))\s?\((?P<conditional>.*)\)
```

## Comment/Preprocessors

- #define
- #include
- //

```
((\/\/.*)|(\#.*))
```

## Comparison

- <
- >
- <=
- >=
- ==

```
(\>?\<?\=?)
```

## Increment/Decrement

- abc++
- abc--

```
(?P<var>\w+)(?P<modifier>(\+|\-){2})
```


