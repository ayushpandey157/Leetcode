# Write your MySQL query statement below
# Write your MySQL query statement below
with method as(
    select class , count(class) as county
    from courses 
    group by class
)
select class from method where county>=5