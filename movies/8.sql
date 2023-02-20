---------------------------------
-- From our beloved Land of Papua we write this code
--
--
-- query to list the names of all people who starred in Toy Story
----------------------------------

select name from people
join stars on stars.person_id=people.id
join movies on stars.movie_id=movies.id
where movies.title="Toy Story";