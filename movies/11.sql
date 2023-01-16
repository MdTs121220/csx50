---------------------------------
-- Markus Dwiyanto Tobi Sogen
-- CS50 for teachers
-- Indonesia
-- query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
----------------------------------

select movies.title from movies
join stars on stars.movie_id=movies.id
join people on stars.person_id=people.id
join ratings on ratings.movie_id=movies.id
where people.name="Chadwick Boseman"
order by ratings.rating desc limit 5;