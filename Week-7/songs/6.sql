-----------------------------------
--- From our beloved Land of Papua we write this code
----
----
-- query that lists the names of songs that are by Post Malone
----------------------------------

SELECT name FROM songs
WHERE artist_id = (SELECT id FROM artists WHERE name == "Post Malone");