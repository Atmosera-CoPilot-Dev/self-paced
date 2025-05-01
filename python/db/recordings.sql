/*
This file contains the MySql code for creating the tables in the recordings database.
Use 'source path/to/file' to run this file in the MySql command line.
Requirements:
- MySql version 8.0.23 or higher
*/

/*
Create the MySQL database 'recordings' if it does not exist.
*/
CREATE DATABASE IF NOT EXISTS recordings;

-- set recordings as the default database
USE recordings;

/*
Create a table 'album' if it does not exist.
The table has the following columns:
- id: an integer that is the primary key of the table
- title: a string that is the title of the album
- artist: a string that is the name of the artist
- price: a float that is the price of the album
*/
CREATE TABLE IF NOT EXISTS album (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    artist VARCHAR(255) NOT NULL,
    price FLOAT NOT NULL
);

/*
Insert some data into the 'album' table.
*/
INSERT INTO album (title, artist, price) VALUES ('The Dark Side of the Moon', 'Pink Floyd', 19.99);
INSERT INTO album (title, artist, price) VALUES ('Abbey Road', 'The Beatles', 17.99);
INSERT INTO album (title, artist, price) VALUES ('Thriller', 'Michael Jackson', 15.99);
INSERT INTO album (title, artist, price) VALUES ('Back in Black', 'AC/DC', 14.99);


