# cop-4520-as2

## Problem 1 Analysis

### Strategy

Label the first person to enter the maze as the checker. The checker will maintain a counter representing the fewest possible number of guests who have entered the maze. When this counter reaches *n*, all the guests have entered.

The checker is allowed to replace the cupcake, but is not allowed to eat it. The rest of the guests are allowed to eat the cupcake (at most once each), but are not allowed to replace it.

If the checker enters the maze and sees that the cupcake is gone, it is proof that at least one person who had not eaten the cupcake yet has eaten the cupcake, and the checker shall update his counter and replace the cupcake.

If any other guest enters the maze and sees the cupcake, they will eat it if and only if they have not eaten a cupcake yet.

## Problem 2 Analysis

### Strategy 1

#### Pros

- Simple, easy to implement

#### Cons

- May lead to large queue outside the showroom door
- May lead to starvation: it is possible that a guest might never get to see the vase

### Strategy 2

#### Pros

- Eliminates the need for queue outside the showroom door

#### Cons

- May lead to starvation: it is possible that a guest might never get to see the vase

### Strategy 3

#### Pros

- No starvation: guests are processed on a first come, first served basis

#### Cons

- May lead to large queue outside the showroom door
- May lead to deadlock: if the last guest in the queue leaves the room, he has no one to notify that the showroom is open

### Selected Strategy

I selected strategy 2 to implement.