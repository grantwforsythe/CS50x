SELECT name FROM songs
JOIN artists
ON songs.artist_id = artists.id
WHERE name = "Post Malone";