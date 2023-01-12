---------------------------------
-- Markus Dwiyanto Tobi Sogen
-- CS50 for teachers
-- Indonesia
-- query that returns the average energy of songs that are by Drake
----------------------------------

SELECT avg(energy) FROM songs
WHERE artist_id = (SELECT id FROM artists WHERE name == "Drake");