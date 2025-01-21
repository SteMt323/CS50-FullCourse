SELECT DISTINCT a.name
FROM people a
INNER JOIN stars s ON a.id = s.person_id
INNER JOIN stars ss ON s.movie_id = ss.movie_id
WHERE ss.person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958) AND a.id != ss.person_id;
