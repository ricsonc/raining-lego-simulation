# raining-lego-simulation

====

Consider a 1x1x2 lego piece: width 1, height 1, length 2. Take an infinite 3d grid with a floor at z = 0. Suppose these 1x1x2 lego pieces start raining down on the grid from the sky. 

The lego pieces rain down in any horizontal orientation at random, and stop either when they hit the ground, or hit another lego piece. It is apparent that this will create empty spaces and overhangs which are not filled by other lego pieces.

As more and more legos accumulate, a sponge-like structure consisting of lego pieces and empty spaces is formed. One natural question is what the density of this structure is. 

This is a numerical simulation of that model. The density is 0.3473184
