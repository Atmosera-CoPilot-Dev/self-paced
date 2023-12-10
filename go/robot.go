package main

import (
	_ "fmt"
	_ "math"
)

/* 1)
Define a type "direction" based on the built-in type int
*/

/* 2)
Create an enumeration of type direction with named constants north, south, east, and west
Use iota to set the sequence
*/

/* 3)
Define a type named "robot" based on struct
Add the following fields:
name (string)
x, y (int)
direction (direction)
*/

/* 4)
Create a method of robot named "initialize" that takes an argument of type string
Assign the argument to the name field of the robot
*/

/*  5)
Create a method of robot named "move" that takes an argument of type direction
Using a switch statement:
increment x if the direction is north,
increment y if the direction is east,
decrement x if the direction is west,
decrement y if the direction is south,
*/

/* 6)
Create a method of robot named "calculateDistance" that returns a value of type float64
Using math.Sqrt, calculate the distance from the center using
the formula for the hypotenuse: sqrt(x * x + y * y)
Return the value
*/

/* 7)
In main():
Create a robot
Set the name to "tobor"
Move north, east, north, north
Print the coordinates and the distance from the center
The output sould look like this:
Location: (1, 3)
Distance from center: 3.162278
*/
func main() {

}
