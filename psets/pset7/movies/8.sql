-- the names of all people who starred in Toy Story
SELECT people.name FROM people
INNER JOIN
    stars ON people.id = stars.person_id
INNER JOIN
    movies ON stars.movie_id = movies.id
WHERE movies.title LIKE 'Toy Story';