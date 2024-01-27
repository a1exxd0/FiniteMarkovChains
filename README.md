# Introduction
Finite state space-based calculator for probabilities of certain transitions in a Markov chain.

## What it does currently
So far takes in hard-coded values for state space and transition matrix and calculates eigenvalues appropriately.

Now can solve for the probability of a state transition in any number of steps for a 3x3 matrix. Adjust transition matrix in 'inputs.cpp' accordingly.

To change number of steps, go into main.cpp and update 'int steps =' to a number of your choosing!

## Details: implementations and upcoming
Looking to have a system where I can calculate the probability of a particular state change in 'n' steps.

I will likely write a smaller version first that works for 3x3 transition matrices, and then move to automation after understanding the mathematics more as I reach completion.

Also will look at extensions, like expected time to enter an absorbing state, or subset of states, etc.

# Final notes
Happy messing!
