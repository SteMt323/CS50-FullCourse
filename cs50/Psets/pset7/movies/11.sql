SELECT a.title
FROM movies a
INNER JOIN stars s ON a.id = s.movie_id
INNER JOIN ratings d ON a.id = d.movie_id
WHERE s.person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman')
ORDER BY  d.rating DESC LIMIT 5;
