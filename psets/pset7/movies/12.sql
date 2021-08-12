SELECT title FROM movies
WHERE id IN (
    SELECT stars.movie_id FROM stars
    INNER JOIN people ON stars.person_id = people.id
    WHERE people.name = 'Johnny Depp'
    INTERSECT
    SELECT stars.movie_id FROM stars
    INNER JOIN people ON stars.person_id = people.id
    WHERE people.name = 'Johnny Depp'
);