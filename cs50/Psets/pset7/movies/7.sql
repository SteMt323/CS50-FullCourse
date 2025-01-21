SELECT s.title, a.rating
FROM movies s
INNER JOIN ratings a ON s.id = a.movie_id
WHERE s.year == 2010
ORDER BY a.rating DESC, s.title;
