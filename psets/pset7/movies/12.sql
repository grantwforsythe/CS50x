-- the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred
SELECT title FROM movies
WHERE id IN (
    SELECT stars.movie_id FROM stars
    INNER JOIN people ON stars.person_id = people.id
    WHERE people.name = 'Johnny Depp'
    INTERSECT
    SELECT stars.movie_id FROM stars
    INNER JOIN people ON stars.person_id = people.id
    WHERE people.name = 'Helena Bonham Carter'
);