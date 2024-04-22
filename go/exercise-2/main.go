/*
Create a Go program that connects to a MySQL database 'recordings' and queries the database for albums by a given artist.

The 'recordings' database is created using the script provided in the 'recordings.sql' file.
*/

package main

// import a package for MySQL driver

import (
	"os"
	"database/sql"
	"fmt"
	"log"
	_ "strings"

	_ "github.com/go-sql-driver/mysql" // use go get -u github.com/go-sql-driver/mysql to install the package
)

// Create a struct to represent an Album as defined in the database
type Album struct {
	ID     int
	Title  string
	Artist string
	Price  float32
}

// declare a global variable to store the database connection
var db *sql.DB

func main() {
	/* 
	main is the entry point of the program.
	It connects to a MySQL database using the password retrieved from the environment variable MYSQLDBPW.
	If the password is not set, the program will exit with a fatal error.
	It then opens a connection to the "recordings" database and pings the database to check the connection.
	If the connection is successful, it prints a success message. 
	*/

	// lookup the password from the environment variable MYSQLDBPW
	password := os.Getenv("MYSQLDBPW")
// if the password is not set, exit the program
	if password == "" {
		log.Fatal("MYSQLDBPW environment variable not set")
	}

	// open a connection to the MySQL database
	var err error
	db, err = sql.Open("mysql", fmt.Sprintf("root:%s@tcp(127.0.0.1:3306)/recordings", password))
	if err != nil {
		log.Fatal(err)
	}
	// close the database connection when the function returns
	defer db.Close()

	// ping the database to check the connection
	err = db.Ping()
	if err != nil {
		log.Fatal(err)
	}

	// print a success message if the connection is successful
	fmt.Println("Successfully connected to the database")

	// call the albumsByArtist function with the artist name "John Coltrane"
	albums, err := albumsByArtist("Pink Floyd")
	if err != nil {
		log.Fatal(err)
	}

	// print the albums returned by the function
	for _, album := range albums {
		fmt.Printf("ID: %d, Title: %s, Artist: %s, Price: %.2f\n", album.ID, album.Title, album.Artist, album.Price)
	}

}

/*
Generate a function 'albumsByArtist' that takes a string argument 'artist' and returns a slice of 'Album' structs.
The function should query the database for albums by the given artist and return the results.
*/

func albumsByArtist(artist string) ([]Album, error) {
	// query the database for albums by the given artist
	rows, err := db.Query("SELECT * FROM album WHERE artist = ?", artist)
	if err != nil {
		return nil, err
	}
	defer rows.Close()

	// create a slice to store the results
	var albums []Album

	// iterate over the rows and scan the data into Album structs
	for rows.Next() {
		var album Album
		err := rows.Scan(&album.ID, &album.Title, &album.Artist, &album.Price)
		if err != nil {
			return nil, err
		}
		albums = append(albums, album)
	}

	// check for errors during iteration
	// if an error is encountered, return an error message with the error and artist name
	if err := rows.Err(); err != nil {
		return nil, fmt.Errorf("error scanning rows for artist %s: %v", artist, err)
	}
	// return the slice of Album structs
	return albums, nil
}