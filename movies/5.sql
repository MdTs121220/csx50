---------------------------------
-- From our beloved Land of Papua we write this code
--
--
-- query to list the titles and release years of all Harry Potter movies, in chronological order
----------------------------------

select title, year from movies
where title like 'Harry Potter%'
order by year;