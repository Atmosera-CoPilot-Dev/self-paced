CREATE DATABASE IF NOT EXISTS recordings;


USE recordings;

CREATE TABLE IF NOT EXISTS album (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    artist VARCHAR(255) NOT NULL,
    price FLOAT NOT NULL
);


INSERT INTO album (title, artist, price) VALUES ('The Dark Side of the Moon', 'Pink Floyd', 19.99);
INSERT INTO album (title, artist, price) VALUES ('Abbey Road', 'The Beatles', 17.99);
INSERT INTO album (title, artist, price) VALUES ('Thriller', 'Michael Jackson', 15.99);
INSERT INTO album (title, artist, price) VALUES ('Back in Black', 'AC/DC', 14.99);


