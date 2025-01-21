SELECT s.name
FROM people s
INNER JOIN directors a ON s.id = a.person_id
INNER JOIN ratings d ON a.movie_id = d.movie_id
WHERE d.rating >= 9.0;
