---------------------------------
-- From our beloved Land of Papua we write this code
--
--
-- query to list the names of all people who starred in a movie in which Kevin Bacon also starred
----------------------------------

select name from people
join stars on stars.person_id=people.id
join movies on stars.movie_id=movies.id
where movies.id in (select movies.id from movies
join people on stars.person_id=people.id
join stars on stars.movie_id=movies.id
where people.name="Kevin Bacon"
and people.birth=1958)
and people.name != "Kevin Bacon";