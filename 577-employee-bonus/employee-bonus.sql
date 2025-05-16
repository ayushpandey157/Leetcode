Select 
      e.name,
      b.bonus 
From Employee e
Left Join Bonus b
On e.empId=b.empId
Where (bonus is null or b.bonus < 1000)