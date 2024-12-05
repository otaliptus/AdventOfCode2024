### Day 5

That was an interesting day.

##### Part 1
Problem basically gives you (X, Y) rule pairs such that X should always appear before Y, and then gives you some query lists. Finding median is the unnecessary part, the problem is to determine whether a list suits to the rules.

I initially considered typical topological sort or Kosaraju, but it seemed too hard for a Day 5 problem. I still decided to implement it quickly with multiple DAGs but after some time I realized problem does not consider transitive rules. Inputs were not hard, so I was allowed to keep it simpler.

Then the problem reduces into whether you want to do a typical O(N^2) avg or not - I hate it. Thus I threw a bunch of data structures to optimize a tiny bit with some tricks. It worked as expected, but that was not the easiest problem for sure.

##### Part 2

Same as part 1 but you need to sort later, which is where standard library comes to help. Handled it very quickly.

-----

Overall interesting day, harder solution would satisfy a lot more but here we are with such laziness.
