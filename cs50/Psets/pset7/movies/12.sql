SELECT a.title
FROM movies a
INNER JOIN stars s ON a.id = s.movie_id
INNER JOIN stars ss ON a.id = ss.movie_id
WHERE s.person_id = (SELECT id FROM people WHERE name = 'Johnny Depp') AND ss.person_id = (SELECT id From people WHERE name = 'Helena Bonham Carter');
