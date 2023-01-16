---------------------------------
-- Markus Dwiyanto Tobi Sogen
-- CS50 for teachers
-- Indonesia
-- query to list the names of all people who have directed a movie that received a rating of at least 9.0
----------------------------------

select name from people
join directors on directors.person_id=people.id
join movies on directors.movie_id=movies.id
join ratings on ratings.movie_id=movies.id
where ratings.rating >= 9.0;