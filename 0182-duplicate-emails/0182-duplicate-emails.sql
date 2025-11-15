/* Write your PL/SQL query statement below */
select email as Email from person
group by email
having count(*)>1;