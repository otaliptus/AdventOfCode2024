### Day 2

I liked part 2 even though it had too many if's.

##### Part 1
Per each line of numbers, check whether they're uniquely increasing / decreasing with differences of {1, 2, 3}.
Given abundance of numbers per lines, I checked the first two integers, determined whether it is increasing or decreasing, and continued from there.

##### Part 2
You may remove one number from the list. This is actually nice - you get two options:
a) Copy list, remove numbers one by one, check: Time complexity increases massively, no need.

b) Copy list, keep two flags, in one pass check for both increasing and decreasing cases. Once a bad number comes up, flag it and move on till the end. If you still detect bad numbers after flagging, answer is no.

However, option b) is not enough as removing the first number can actually make the list good as well. So, you can either re-iterate by removing / ignoring the first element and make two passes, or you can integrate it into the solution above in the most ugliest way possible to do it all in one pass like me.
