-- the names of all people who starred in a movie in which Kevin Bacon also starred
SELECT people.name FROM people
INNER JOIN
    stars ON people.id = stars.person_id
WHERE stars.movie_id IN (
    -- all of the movies Kevin Bacon is in
    SELECT movie_id FROM stars
    INNER JOIN
        people ON stars.person_id = people.id
    WHERE
        (people.name = 'Kevin Bacon' AND people.birth = 1958)
)
EXCEPT
SELECT name FROM people
WHERE
    name = 'Kevin Bacon'
AND
    birth = 1958;