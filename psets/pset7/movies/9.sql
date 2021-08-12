SELECT people.name FROM people
INNER JOIN
    stars ON people.id = stars.person_id
INNER JOIN
    movies ON movies.id = stars.movie_id
WHERE movies.year=2004
GROUP BY people.id
ORDER BY people.birth;