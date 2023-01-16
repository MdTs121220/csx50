---------------------------------
-- Markus Dwiyanto Tobi Sogen
-- CS50 for teachers
-- Indonesia
-- query to list the names of all people who starred in a movie released in 2004, ordered by birth year
----------------------------------

select distinct name from people
join stars on stars.person_id=people.id
join movies on stars.movie_id=movies.id
join ratings on ratings.movie_id=movies.id
where movies.year=2004
order by people.birth;