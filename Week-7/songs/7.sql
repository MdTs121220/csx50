-----------------------------------
--- From our beloved Land of Papua we write this code
----
----
-- query that returns the average energy of songs that are by Drake
----------------------------------

SELECT avg(energy) FROM songs
WHERE artist_id = (SELECT id FROM artists WHERE name == "Drake");