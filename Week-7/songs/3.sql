-----------------------------------
--- From our beloved Land of Papua we write this code
----
----
-- query to list the names of the top 5 longest songs, in descending order of length
----------------------------------

SELECT name FROM songs
ORDER BY duration_ms DESC LIMIT 5;