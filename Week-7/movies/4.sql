---------------------------------
-- From our beloved Land of Papua we write this code
--
--
-- query to determine the number of movies with an IMDb rating of 10.0
----------------------------------

select count(movies.id) from movies
join ratings on movies.id=ratings.movie_id
and ratings.rating=10;