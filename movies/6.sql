---------------------------------
-- Markus Dwiyanto Tobi Sogen
-- CS50 for teachers
-- Indonesia
-- query to determine the average rating of all movies released in 2012
----------------------------------

select avg(rating) from ratings
join movies on movies.id=ratings.movie_id
where movies.year=2012;