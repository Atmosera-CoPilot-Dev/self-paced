package main

import (
	"fmt"
	"math"
)

/*
Define a type "direction" based on the built-in type int
*/
type direction int

/*
Create an enumeration of type direction with named constants north, south, east, and west
Use iota to set the sequence
*/
const (
	north direction = iota
	east
	south
	west
)

/*
Define a type named "robot" based on struct
Add the following fields:
name (string)
x, y (int)
direction (direction)
*/
type robot struct {
	name      string
	x, y      int
	direction direction
}

/*
Create a method of robot named "initialize" that takes an argument of type string
Assign the argument to the name field of the robot
*/
func (r *robot) initialize(name string) {
	r.name = name
}

/*
Create a method of robot named "move" that takes an argument of type direction
Using a switch statement:
increment x if the direction is north,
increment y if the direction is east,
decrement x if the direction is west,
decrement y if the direction is south,
*/
func (r *robot) move(dir direction) {
	switch dir {
	case north:
		r.y++
	case east:
		r.x++
	case south:
		r.y--
	case west:
		r.x--
	}
}
/*
Create a method of robot named "calculateDistance" that returns a value of type float64
Using math.Sqrt, calculate the distance from the center using
the formula for the hypotenuse: sqrt(x * x + y * y)
Return the value
*/
func (r robot) calculateDistance() float64{
	distance := math.Sqrt(float64(r.x * r.x) + float64(r.y * r.y))
	return distance
}

/*
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
	tobor := robot{}
	tobor.initialize("Tobor")
	tobor.move(north)
	tobor.move(east)
	tobor.move(north)
	tobor.move(north)
	
	fmt.Printf("Location: (%d, %d)\nDistance from center: %f", tobor.x, tobor.y, tobor.calculateDistance())
}
