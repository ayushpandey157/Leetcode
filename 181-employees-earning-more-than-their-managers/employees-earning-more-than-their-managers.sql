# Write your MySQL query statement below
select e1.name as Employee 
from employee e1 
join employee e2 
on e2.id=e1.managerId
where e1.salary>e2.salary