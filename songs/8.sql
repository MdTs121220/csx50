-----------------------------------
--- From our beloved Land of Papua we write this code
----
----
-- query that lists the names of the songs that feature other artists
----------------------------------

SELECT name FROM songs
WHERE name LIKE "%feat.%";