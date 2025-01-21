SELECT s.name
FROM people s
INNER JOIN stars a ON s.id = a.person_id
INNER JOIN movies d ON a.movie_id = d.id
WHERE d.year = 2004
ORDER BY s.birth;
