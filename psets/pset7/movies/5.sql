-- all Harry Potter movies, in chronological order
SELECT title, year FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year ASC;