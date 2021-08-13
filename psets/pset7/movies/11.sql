-- the titles of the five highest rated movies (in order) that Chadwick Boseman starred in,
-- starting with the highest rated 
SELECT movies.title FROM movies
INNER JOIN
    stars ON movies.id = stars.movie_id
INNER JOIN
    people ON stars.person_id = people.id
INNER JOIN
    ratings ON movies.id = ratings.movie_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;