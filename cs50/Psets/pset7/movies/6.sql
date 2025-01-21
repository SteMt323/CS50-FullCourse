SELECT AVG(s.rating)
FROM ratings s
INNER JOIN movies a ON a.id = s.movie_id
WHERE a.year == 2012;
