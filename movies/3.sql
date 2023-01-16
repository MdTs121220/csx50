---------------------------------
-- Markus Dwiyanto Tobi Sogen
-- CS50 for teachers
-- Indonesia
-- query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
----------------------------------

select title from movies where year >= 2018
order by title ASC;