# Write your MySQL query statement below
Select e.name,b.bonus From Employee e
LEFT JOIN Bonus b ON e.empId=b.empId
WHERE b.bonus<1000 OR b.bonus is NULL;