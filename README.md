# combinatoric

tis is the begin of a collection of combinatorics tools

## combinations iterator
e.g. iteration over 3 dimensional combination of value set {a,b} results in:
```
  a a a
  b a a
  a b a
  b b a
  a a b
  b a b
  a b b
  b b b
```

```
  #define COMBINTATORIC_IMPL
  #include "combinatori.h"
  combinatoric_combination_iterator_t iter = combinatoric_combination_iterator(VALS, DIMS, buffer);
  size_t next[DIMS];
  while(combinatoric_combination_iterator_next(&iter, next))
  {
    do_someting_with_combination(next);
  }
```

## ToDo
more ideas
- choices
- permutations
