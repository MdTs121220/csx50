---------------------------------
-- Markus Dwiyanto Tobi Sogen
-- CS50 for teachers
-- Indonesia
-- query that lists the names of the songs that feature other artists
----------------------------------

SELECT name FROM songs
WHERE name LIKE "%feat.%";