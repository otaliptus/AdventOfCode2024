### Day 3

I hate string matching problems. I thought this problem could be a lot more interesting & fun if mul(A, B) was enabled to be recursive, like mul(mul(A, B), mul(C, D)). Kind of expected that for the part 2 but did not happen.

##### Part 1

Determine mul(A, B) in a string and execute and sum them.

I just put hacky if's in C++ to not to allocate memory each time with substr()'s (and I did not want to deal with std::find() as well).

Too ugly yet works good enough.

##### Part 2

Some more string matching, does not add real value to the problem.
