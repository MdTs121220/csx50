---------------------------------
-- From our beloved Land of Papua we write this code
--
--
-- query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred
----------------------------------

select title from movies
join stars on stars.movie_id=movies.id
join people on stars.person_id=people.id
where people.name="Johnny Depp"
and title in ( select title from movies join stars on stars.movie_id=movies.id
join people on stars.person_id=people.id
where people.name="Helena Bonham Carter"
);