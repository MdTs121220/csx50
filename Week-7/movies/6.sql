---------------------------------
-- From our beloved Land of Papua we write this code
--
--
-- query to determine the average rating of all movies released in 2012
----------------------------------

select avg(rating) from ratings
join movies on movies.id=ratings.movie_id
where movies.year=2012;